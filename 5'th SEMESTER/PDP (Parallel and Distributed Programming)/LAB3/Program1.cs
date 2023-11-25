using System;
using System.Collections.Generic;
using System.Threading;

class Program1
{
    static void Main1()
    {
        int rows = 1000;
        int cols = 1000;

        // Creating matrix A with dimensions 1000x1000
        List<List<int>> A = new List<List<int>>();
        for (int i = 0; i < rows; i++)
        {
            A.Add(new List<int>());
            for (int j = 0; j < cols; j++)
            {
                A[i].Add(j + 1); // Fill with some data for demonstration (1, 2, 3, ...)
            }
        }

        // Creating matrix B with dimensions 1000x1000
        List<List<int>> B = new List<List<int>>();
        for (int i = 0; i < rows; i++)
        {
            B.Add(new List<int>());
            for (int j = 0; j < cols; j++)
            {
                B[i].Add((j + 1) * 2); // Fill with some data for demonstration (2, 4, 6, ...)
            }
        }

        // Creating Result matrix with dimensions 1000x1000 initialized to 0
        List<List<int>> Result = new List<List<int>>();
        for (int i = 0; i < rows; i++)
        {
            Result.Add(new List<int>());
            for (int j = 0; j < cols; j++)
            {
                Result[i].Add(0);
            }
        }

        int numberOfTasks = 1000;
        List<Thread> threads = new List<Thread>();

        var start = DateTime.Now;

        // row-wise split
        /*
        for (int i = 0; i < numberOfTasks; ++i)
        {
            int taskNum = i;
            threads.Add(new Thread(() => ComputeTaskRow(A, B, Result, taskNum, numberOfTasks)));
        }
        */

        // column-wise split
        /*
        for (int i = 0; i < numberOfTasks; ++i)
        {
            int taskNum = i;
            threads.Add(new Thread(() => ComputeTaskColumn(A, B, Result, taskNum, numberOfTasks)));
        }
        */

        // stride split
        for (int i = 0; i < numberOfTasks; ++i)
        {
            int taskNum = i;
            threads.Add(new Thread(() => ComputeTaskStride(A, B, Result, taskNum, numberOfTasks)));
        }


        foreach (var thread in threads)
        {
            thread.Start();
        }

        foreach (var thread in threads)
        {
            thread.Join();
        }

        var finish = DateTime.Now;
        var elapsed = finish - start;

        Console.WriteLine($"Time: {elapsed.TotalSeconds} seconds");
    }

    static void PrintMatrix(List<List<int>> matrix)
    {
        foreach (var row in matrix)
        {
            foreach (var val in row)
            {
                Console.Write(val + " ");
            }
            Console.WriteLine();
        }
    }

    static int ComputeElement(List<List<int>> A, List<List<int>> B, int row, int col)
    {
        int sum = 0;
        for (int i = 0; i < A[0].Count; ++i)
        {
            sum += A[row][i] * B[i][col];
        }
        return sum;
    }

    static Tuple<int, int> GetTaskRange(int taskNum, int totalTasks, int totalElements)
    {
        int baseElements = totalElements / totalTasks;
        int extraElements = totalElements % totalTasks;
        int start = taskNum * baseElements + Math.Min(taskNum, extraElements);
        int end = start + baseElements + (taskNum < extraElements ? 1 : 0);
        return Tuple.Create(start, end);
    }

    static void ComputeTaskRow(List<List<int>> A, List<List<int>> B, List<List<int>> Result, int taskNum, int totalTasks)
    {
        int totalElements = A.Count * B[0].Count;
        var range = GetTaskRange(taskNum, totalTasks, totalElements);
        int cols = B[0].Count;

        //Console.WriteLine($"Task {taskNum} starting.");

        for (int index = range.Item1; index < range.Item2; ++index)
        {
            int row = index / cols;
            int col = index % cols;
            int res = ComputeElement(A, B, row, col);

            Result[row][col] = res;
        }

        //Console.WriteLine($"Task {taskNum} finished.");
    }

    static void ComputeTaskColumn(List<List<int>> A, List<List<int>> B, List<List<int>> Result, int taskNum, int totalTasks)
    {
        int totalElements = A.Count * B[0].Count;
        var range = GetTaskRange(taskNum, totalTasks, totalElements);
        int rows = A.Count;

        //Console.WriteLine($"Task {taskNum} starting.");

        for (int index = range.Item1; index < range.Item2; ++index)
        {
            int col = index / rows;
            int row = index % rows;
            int res = ComputeElement(A, B, row, col);
            Result[row][col] = res;
        }

        //Console.WriteLine($"Task {taskNum} finished.");
    }

    static void ComputeTaskStride(List<List<int>> A, List<List<int>> B, List<List<int>> Result, int taskNum, int totalTasks)
    {
        int rows = A.Count;
        int cols = B[0].Count;

        //Console.WriteLine($"Task {taskNum} starting.");

        for (int index = taskNum; index < rows * cols; index += totalTasks)
        {
            int row = index / cols;
            int col = index % cols;
            int res = ComputeElement(A, B, row, col);
            Result[row][col] = res;
        }

        //Console.WriteLine($"Task {taskNum} finished.");
    }
}
