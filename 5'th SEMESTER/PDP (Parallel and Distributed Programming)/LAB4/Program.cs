using System.Diagnostics;
using System.Data;
using static System.Net.WebRequestMethods;

namespace LAB4;
public class Program
{
    static void Main()
    {
        Stopwatch stopwatch = new Stopwatch();
        var hosts = new List<string>
        {
            "slowwonderoustranscendentbirds.neverssl.com/online/"
        };

        Console.WriteLine("CALLBACK");
        stopwatch.Start();
        Callback.Run(hosts);
        stopwatch.Stop();
        TimeSpan directCallbackTime = stopwatch.Elapsed;

        Thread.Sleep(3000);

        Console.WriteLine("\nTASK");
        stopwatch.Restart();
        Tasks.Run(hosts);
        stopwatch.Stop();
        TimeSpan taskMechanismTime = stopwatch.Elapsed;

        Thread.Sleep(3000);

        Console.WriteLine("\nASYNC TASK");
        stopwatch.Restart();
        AsyncTasks.Run(hosts);
        stopwatch.Stop();
        TimeSpan asyncTaskMechanismTime = stopwatch.Elapsed;

        Console.WriteLine("CALLBACK: {0}", directCallbackTime);
        Console.WriteLine("TASK: {0}", taskMechanismTime);
        Console.WriteLine("ASYNC TASK: {0}", asyncTaskMechanismTime);
    }
}