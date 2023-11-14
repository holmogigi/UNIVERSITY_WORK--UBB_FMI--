using System;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;

class Program
{
    static object mutex = new object();
    static Queue<int> productsBuff = new Queue<int>();
    static int scalarProd = 0;

    static void Producer()
    {
        List<int> v1 = new List<int> { 1, 2, 3, 4};
        List<int> v2 = new List<int> { 5, 6, 7, 8};

        for (int i = 0; i < v1.Count; i++)
        {
            Thread.Sleep(100);
            int product = v1[i] * v2[i];
            Console.WriteLine("Producer has product = " + product);

            lock (mutex)
            {
                productsBuff.Enqueue(product);
                Monitor.PulseAll(mutex);
            }
        }
    }

    static void Consumer()
    {
        for (int i = 0; i < 4; i++)
        {
            //Thread.Sleep(100);

            lock (mutex)
            {
                while (productsBuff.Count == 0)
                {
                    Monitor.Wait(mutex);
                }

                int product = productsBuff.Dequeue();
                scalarProd += product;
                Console.WriteLine("Consumer has scalar product = " + scalarProd);
            }
        }
    }

    static void Main()
    {
        Task producerTask = Task.Run(() => Producer());
        Task consumerTask = Task.Run(() => Consumer());

        Task.WhenAll(producerTask, consumerTask).Wait();

        Console.WriteLine("Scalar Product = " + scalarProd);
    }
}
