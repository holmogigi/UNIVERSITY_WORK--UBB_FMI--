Common requirements:

-The problems will require to execute a number of independent operations, that operate on shared data.

-There shall be several threads launched at the beginning, and each thread shall execute a lot of operations. The operations to be executed are to be randomly choosen, and with randomly choosen parameters.

-The main thread shall wait for all other threads to end and, then, it shall check that the invariants are obeyed.

-The operations must be synchronized in order to operate correctly. Write, in a documentation, the rules (which mutex what invariants it protects).

-You shall play with the number of threads and with the granularity of the locking, in order to asses the performance issues. Document what tests have you done, on what hardware platform, for what size of the data, and what was the time consumed.

-

Statement: 

At a bank, we have to keep track of the balance of some accounts. Also, each account has an associated log (the list of records of operations performed on that account). Each operation record shall have a unique serial number, that is incremented for each operation performed in the bank.
We have concurrently run transfer operations, to be executer on multiple threads. Each operation transfers a given amount of money from one account to someother account, and also appends the information about the transfer to the logs of both accounts.
From time to time, as well as at the end of the program, a consistency check shall be executed. It shall verify that the amount of money in each account corresponds with the operations records associated to that account, and also that all operations on each account appear also in the logs of the source or destination of the transfer.
Two transaction involving distinct accounts must be able to proceed independently (without having to wait for the same mutex).
