package org.example;
import java.util.Scanner;

import org.example.controller.CalculatorController;
import org.example.view.MyView;

public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        while(true)
        {
            MyView.PrintOperationChoice();
            String input = scanner.next();
            if (input.equals("EXIT"))
            {
                MyView.PrintExit();
                break;
            }
            double result;
            MyView.PrintFirstNumberChoice();
            int first = scanner.nextInt();
            if (input.equals("sqrt"))
            {
                result = CalculatorController.Calculate(input, first, 0);
                MyView.PrintResult(result);
            }
            else
            {
                MyView.PrintSecondNumberChoice();
                int second = scanner.nextInt();
                result = CalculatorController.Calculate(input, first, second);
                MyView.PrintResult(result);
            }
        }
    }
}