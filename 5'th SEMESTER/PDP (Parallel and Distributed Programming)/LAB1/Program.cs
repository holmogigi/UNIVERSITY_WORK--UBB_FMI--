using System;
using System.Collections.Generic;
using System.Threading;
using System.Linq;
using System.Security.Principal;

public class BankAccount
{
    public int AccountId { get; }

    public decimal Balance { get; private set; }

    public decimal InitialBalance { get; }

    public List<Transaction> transactionLog;

    public BankAccount(int accountId, decimal initialBalance, decimal balance)
    {
        AccountId = accountId;
        Balance = balance;
        InitialBalance = initialBalance;
        transactionLog = new List<Transaction>();
    }

    public void Transfer(BankAccount sourceAccount, BankAccount targetAccount, decimal amount, BankAccountMutex mutex, int transactionId)
    {
        var orderedAccounts = new List<BankAccount> { sourceAccount, targetAccount };
        orderedAccounts = orderedAccounts.OrderBy(acc => acc.AccountId).ToList();

        mutex.LockAccounts(orderedAccounts.ToArray());
        try
        {
            if (Balance >= amount)
            {
                Balance -= amount;
                targetAccount.Deposit(amount, sourceAccount, mutex, transactionId);
                transactionLog.Add(new Transaction(transactionId, this, targetAccount, amount));
            }
            else
            {
                Console.WriteLine($"Insufficient funds in account {AccountId} for the transfer.");
            }
        }
        finally
        {
            mutex.UnlockAccounts(orderedAccounts.ToArray());
        }
    }

    public void Deposit(decimal amount, BankAccount sourceAccount, BankAccountMutex mutex, int transactionId)
    {
        mutex.LockAccount(this);
        try
        {
            Balance += amount;
            transactionLog.Add(new Transaction(transactionId, sourceAccount, this, amount));
        }
        finally
        {
            mutex.UnlockAccount(this);
        }
    }

    public void AddTransaction(BankAccount sourceAccount, decimal amount, BankAccountMutex mutex, int transactionId)
    {
        mutex.LockAccount(this);
        try
        {
            transactionLog.Add(new Transaction(transactionId, sourceAccount, this, amount));
        }
        finally
        {
            mutex.UnlockAccount(this);
        }
    }

    public bool IsConsistent()
    {
        decimal calculatedBalance = InitialBalance;
        List<int> checkedTransactionIds = new List<int>();

        foreach (var transaction in transactionLog)
        {
            if (!checkedTransactionIds.Contains(transaction.TransactionId))
            {
                if (transaction.Destination == this)
                {
                    calculatedBalance += transaction.Amount;
                }
                else if (transaction.Source == this)
                {
                    calculatedBalance -= transaction.Amount;
                }

                checkedTransactionIds.Add(transaction.TransactionId);

                if (transaction.Source != this && transaction.Destination != this)
                {
                    var otherAccount = transaction.Source != this ? transaction.Source : transaction.Destination;
                    if (!otherAccount.transactionLog.Exists(t => t.TransactionId == transaction.TransactionId))
                    {
                        return false;
                    }
                }
            }
        }
        return Balance == calculatedBalance;
    }
}

public class Transaction
{
    public int TransactionId { get; }
    public BankAccount Source { get; }
    public BankAccount Destination { get; }
    public decimal Amount { get; }

    public Transaction(int transactionId, BankAccount source, BankAccount destination, decimal amount)
    {
        TransactionId = transactionId;
        Source = source;
        Destination = destination;
        Amount = amount;
    }

    public override string ToString()
    {
        return $"TransactionId: {TransactionId}, Source: {Source.AccountId}, Destination: {Destination.AccountId}, Amount: {Amount:C}";
    }
}

public class BankAccountMutex
{
    private readonly object locker = new object();
    private readonly HashSet<BankAccount> lockedAccounts = new HashSet<BankAccount>();

    public void LockAccount(BankAccount account)
    {
        lock (locker)
        {
            Monitor.Enter(account);
            lockedAccounts.Add(account);
        }
    }

    public void UnlockAccount(BankAccount account)
    {
        lock (locker)
        {
            lockedAccounts.Remove(account);
            Monitor.Exit(account);
        }
    }

    public void LockAccounts(params BankAccount[] accounts)
    {
        accounts = accounts.OrderBy(acc => acc.AccountId).ToArray();

        lock (locker)
        {
            Monitor.Enter(locker);

            foreach (var account in accounts)
            {
                Monitor.Enter(account);
                lockedAccounts.Add(account);
            }
        }
    }

    public void UnlockAccounts(params BankAccount[] accounts)
    {
        lock (locker)
        {
            foreach (var account in accounts)
            {
                lockedAccounts.Remove(account);
                Monitor.Exit(account);
            }

            Monitor.Exit(locker);
        }
    }
}

public class TransactionManager
{
    private static int transactionIdCounter = 1;

    public static int GetNextTransactionId()
    {
        return Interlocked.Increment(ref transactionIdCounter);
    }
}

public class Program
{
    static void Main(string[] args)
    {
        int numAccounts = 10;
        List<BankAccount> accounts = new List<BankAccount>();

        for (int i = 1; i <= numAccounts; i++)
        {
            accounts.Add(new BankAccount(i, 1000, 1000));
        }

        int numThreads = 4;
        Thread[] threads = new Thread[numThreads];
        BankAccountMutex mutex = new BankAccountMutex();

        int totalTransfers = 100;
        Barrier barrier = new Barrier(numThreads, b =>
        {
            Console.WriteLine("All threads done");
        });

        for (int i = 0; i < numThreads; i++)
        {
            int threadId = i;
            threads[i] = new Thread(() =>
            {
                Random random = new Random();
                int ConsistencyCheckInterval = 10;

                for (int j = 0; j < totalTransfers / numThreads; j++)
                {
                    int sourceAccountId = random.Next(1, numAccounts + 1);
                    int targetAccountId = random.Next(1, numAccounts + 1);
                    if (sourceAccountId != targetAccountId)
                    {
                        decimal amount = (decimal)random.Next(1, 100);
                        BankAccount sourceAccount = accounts[sourceAccountId - 1];
                        BankAccount targetAccount = accounts[targetAccountId - 1];

                        // Get the next TransactionId from the TransactionManager
                        int transactionId = TransactionManager.GetNextTransactionId();

                        sourceAccount.Transfer(sourceAccount, targetAccount, amount, mutex, transactionId);

                        Console.WriteLine($"Thread {threadId} - Transferred {amount:C} from Account {sourceAccount.AccountId} to Account {targetAccount.AccountId}");
                         
                        /*
                        if (totalTransfers % ConsistencyCheckInterval == 0)
                        {
                            Console.WriteLine("Performing consistency check...");
                            foreach (var account in accounts)
                            {
                                foreach (var translog in account.transactionLog)
                                    Console.WriteLine(translog.ToString());

                                if (account.IsConsistent())
                                {
                                    Console.WriteLine($"Account {account.AccountId} is consistent.");
                                }
                                else
                                {
                                    Console.WriteLine($"Account {account.AccountId} is inconsistent.");
                                }
                            }
                        }
                        */
                    }
                }

                barrier.SignalAndWait(); // Signal that this thread has completed its work
            });
        }

        foreach (Thread thread in threads)
        {
            thread.Start();
        }

        foreach (Thread thread in threads)
        {
            thread.Join();
        }

        foreach (var account in accounts)
        {
            Console.WriteLine($"\nAccount {account.AccountId} has balance: {account.Balance:C}");

            foreach (var translog in account.transactionLog)
                Console.WriteLine(translog.ToString());

            if (account.IsConsistent())
            {
                Console.WriteLine($"Account {account.AccountId} is consistent.");
            }
            else
            {
                Console.WriteLine($"Account {account.AccountId} is inconsistent.");
            }
        }
    }
}
