package View;
/*
import Controller.Controller;
import Exceptions.MyException;
import Model.ADT.*;
import Model.Expression.ArithmeticExpression;
import Model.Expression.ValueExpression;
import Model.Expression.VariableExpression;
import Model.ProgramState;
import Model.Statement.*;
import Model.Type.BoolType;
import Model.Type.IntType;
import Model.Value.BoolValue;
import Model.Value.IntValue;
import Model.Value.ValueInterface;
import Repository.Repository;
import Repository.RepositoryInterface;

import java.io.IOException;
import java.util.Scanner;

public class View
{
    public void print_menu()
    {
        System.out.println("!TOY LANGUAGE INTERPRETER!");
        System.out.println("1. Program 1 \nint v;\n" +
                "v=2;\n" +
                "Print(v)\n");
        System.out.println("2. Program 2 \nint a;\n" +
                "a=2+3*5;\n" +
                "int b;\n" +
                "b=a-4;\n" +
                "Print(b)\n");
        System.out.println("3. Program 3\nbool a;\n" +
                "a=false;\n" +
                "int v;\n" +
                "If a Then v=2 Else v=3;\n" +
                "Print(v)\n");
        System.out.println("0. EXIT");
        System.out.println(">>");
    }

    public void steps_menu()
    {
        System.out.println("1. ONE step");
        System.out.println("2. ALL steps");
        System.out.println("0. EXIT");
        System.out.println(">>");
    }

    public void execute_program(StatementInterface statement)
    {
        AdtStackInterface<StatementInterface> exeStack=new AdtStack<StatementInterface>();
        AdtDictionaryInterface<String, ValueInterface> symTable = new AdtDictionary<String, ValueInterface>();
        AdtListInterface<ValueInterface> outList=new AdtList<ValueInterface>();
        ProgramState program=new ProgramState(exeStack,symTable,outList,statement);
        RepositoryInterface repo=new Repository(program, "log.txt");
        Controller contr=new Controller(repo);

        Scanner scanner = new Scanner(System.in);
        int input;
        while(!exeStack.isEmpty())
        {
            steps_menu();
            input=scanner.nextInt();
            if (input==1)
            {
                try{
                    program=contr.single_step(program);
                    System.out.println(program);
                }catch (MyException exception)
                {
                    System.out.println(exception.getMessage());
                }
            }else if (input==2)
            {
                try{
                    contr.all_steps();
                }catch (MyException | IOException exception)
                {
                    System.out.println(exception.getMessage());
                }
            } else if (input==3)
                break;
            else if (input==0)
                System.exit(0);
            else
                System.out.println("!ERROR! Invalid input!");
        }
    }

    public void run()
    {
        //int v;
        //v=2;
        //Print(v)
        StatementInterface exemple1= new CompStatement(new VariableDeclarationStatement("v",new IntType()),
                new CompStatement(new AssignStatement("v",new ValueExpression(new IntValue(2))),
                        new PrintStatement(new VariableExpression("v"))));

        //int a;
        //a=2+3*5;
        //int b;
        //b=a-4;
        //Print(b)
        StatementInterface example2=new CompStatement( new VariableDeclarationStatement("a",new IntType()),
                        new CompStatement(new AssignStatement("a", new ArithmeticExpression('+',new ValueExpression(new IntValue(2)),
                                new ArithmeticExpression('*',new ValueExpression(new IntValue(3)), new ValueExpression(new IntValue(5))))),
                                new CompStatement(new VariableDeclarationStatement("b",new IntType()),
                                new CompStatement(new AssignStatement("b",new ArithmeticExpression('-',new VariableExpression("a"),
                                        new ValueExpression(new IntValue(4)))), new PrintStatement(new VariableExpression("b"))))));

        //bool a;
        //a=false;
        //int v;
        //If a Then v=2 Else v=3;
        //Print(v)
        StatementInterface example3=new CompStatement(new VariableDeclarationStatement("a",new BoolType()),
                        new CompStatement(new AssignStatement("a", new ValueExpression(new BoolValue(false))),
                                new CompStatement(new VariableDeclarationStatement("v", new IntType()),
                                new CompStatement(new IfStatement(new VariableExpression("a"),
                                        new AssignStatement("v",new ValueExpression(new IntValue(2))),
                                        new AssignStatement("v", new ValueExpression(new IntValue(3)))),
                                        new PrintStatement(new VariableExpression("v"))))));

        while (true)
        {
            print_menu();
            int input;
            Scanner scanner=new Scanner(System.in);
            input=scanner.nextInt();
            if (input==1)
                execute_program(exemple1);
            else if (input==2)
                execute_program(example2);
            else if (input==3)
                execute_program(example3);
            else if(input==0)
            {
                System.out.println("\nExiting...\n");
                System.exit(0);
            }
            else
                System.out.println("!ERROR! Input is invalid!");
        }
    }

}
*/