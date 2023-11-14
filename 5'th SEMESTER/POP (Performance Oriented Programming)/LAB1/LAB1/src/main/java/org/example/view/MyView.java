package org.example.view;

public class MyView
{
    public static void PrintOperationChoice()
    {
        System.out.print("\nType EXIT (to close the app) or your operation( + , - , / , * , max , min , sqrt ): ");
    }

    public static void PrintFirstNumberChoice()
    {
        System.out.print("Type the first number: ");
    }

    public static void PrintSecondNumberChoice()
    {
        System.out.print("Type the second number: ");
    }

    public static void PrintExit(){System.out.print("Exiting...\n");}

    public static void PrintResult(double result) { System.out.print("Result: " + result);}
}