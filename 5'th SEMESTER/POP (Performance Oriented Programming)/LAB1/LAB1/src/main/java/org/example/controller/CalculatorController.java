package org.example.controller;
import org.example.model.*;

public class CalculatorController
{
    public static double Calculate(String operator, int a, int b)
    {
        return switch (operator) {
            case "+" -> Add.exe(a, b);
            case "-" -> Sub.exe(a, b);
            case "/" -> Div.exe(a, b);
            case "*" -> Mul.exe(a, b);
            case "min" -> Min.exe(a, b);
            case "max" -> Max.exe(a, b);
            case "sqrt" -> SQR.exe(a);
            default -> 0;
        };
    }
}
