using System;
using System.Collections.Generic;
using System.Threading.Tasks;

public class Program
{
    const int V = 5; // Number of vertices in the graph

    // This method checks if a vertex can be added at pos position in the path
    static bool IsSafe(int v, bool[,] graph, List<int> path, int pos)
    {
        // Check if this vertex is an adjacent vertex of the previously added vertex
        if (!graph[path[pos - 1], v])
            return false;

        // Check if the vertex has already been included
        for (int i = 0; i < pos; i++)
            if (path[i] == v)
                return false;

        return true;
    }

    // A recursive utility function to solve the Hamiltonian Cycle problem
    static List<int> HamCycle(bool[,] graph, List<int> path, int pos)
    {
        // Base case: If all vertices are included in the path
        if (pos == V)
        {
            // And if there is an edge from the last included vertex to the first vertex
            if (graph[path[pos - 1], path[0]])
                return path;
            else
                return new List<int>();
        }

        // Try different vertices as a next candidate in Hamiltonian Cycle
        var tasks = new List<Task<List<int>>>();

        for (int v = 0; v < V; v++)
        {
            // Check if this vertex can be added to pos in the path
            if (IsSafe(v, graph, path, pos))
            {
                var newPath = new List<int>(path);
                newPath[pos] = v;
                tasks.Add(Task.Run(() => HamCycle(graph, newPath, pos + 1)));
            }
        }

        // If adding vertex v doesn't lead to a solution, then remove it
        foreach (var task in tasks)
        {
            var result = task.Result;
            if (result.Count > 0)
                return result;
        }

        return new List<int>();
    }

    // This function solves the Hamiltonian Cycle problem using Backtracking
    public static void FindHamiltonianCycle(bool[,] graph, int startVertex)
    {
        var path = new List<int>(new int[V]);
        path[0] = startVertex;

        // Print the solution
        var resultPath = HamCycle(graph, path, 1);
        lock (new object())
        {
            if (resultPath.Count == 0)
            {
                Console.WriteLine("No Hamiltonian Cycle found.");
            }
            else
            {
                Console.Write("Hamiltonian Cycle found starting from vertex " + startVertex + ": ");
                foreach (int vertex in resultPath)
                    Console.Write(vertex + " ");
                Console.WriteLine(resultPath[0]);
            }
        }
    }

    // Function to generate a random directed graph
    static bool[,] GenerateRandomGraph(int V, double edgeProbability)
    {
        var graph = new bool[V, V];

        var rand = new Random();

        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                if (i != j && rand.NextDouble() < edgeProbability)
                {
                    graph[i, j] = true;
                }
            }
        }

        return graph;
    }

    // Function to print the graph
    static void PrintGraph(bool[,] graph)
    {
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                Console.Write(graph[i, j] ? "1 " : "0 ");
            }
            Console.WriteLine();
        }
    }

    public static void Main()
    {
        bool[,] graph1 = {
            {false, true, false, true, false},
            {true, false, true, true, true},
            {false, true, false, false, true},
            {true, true, false, false, true},
            {false, true, true, true, false},
        };

        PrintGraph(graph1);
        FindHamiltonianCycle(graph1, 4);

        var graph2 = GenerateRandomGraph(V, 0.9);
        PrintGraph(graph2);
        FindHamiltonianCycle(graph2, 3);
    }
}