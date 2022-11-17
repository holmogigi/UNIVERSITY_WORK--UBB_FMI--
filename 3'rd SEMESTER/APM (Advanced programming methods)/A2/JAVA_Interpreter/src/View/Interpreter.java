package View;
import Controller.Controller;
import Exceptions.MyException;
import Model.ADT.*;
import Model.Expression.ArithmeticExpression;
import Model.Expression.RelationalExpression;
import Model.Expression.ValueExpression;
import Model.Expression.VariableExpression;
import Model.ProgramState;
import Model.Statement.*;
import Model.Type.BoolType;
import Model.Type.IntType;
import Model.Type.StringType;
import Model.Value.BoolValue;
import Model.Value.IntValue;
import Model.Value.StringValue;
import Model.Value.ValueInterface;
import Repository.Repository;
import Repository.RepositoryInterface;
import java.io.IOException;
import java.util.Scanner;


public class Interpreter
{

    public void run()
    {
        StatementInterface ex1 = new CompStatement(new VariableDeclarationStatement("v", new IntType()),
                new CompStatement(new AssignStatement("v", new ValueExpression(new IntValue(2))),
                        new PrintStatement(new VariableExpression("v"))));
        ProgramState prg1 = new ProgramState(new AdtStack<>(), new AdtDictionary<>(), new AdtList<>(), ex1, new AdtDictionary<>());
        RepositoryInterface repo1 = new Repository(prg1, "log1.txt");
        Controller controller1 = new Controller(repo1);

        StatementInterface ex2 = new CompStatement(new VariableDeclarationStatement("a",new IntType()),
                new CompStatement(new VariableDeclarationStatement("b",new IntType()),
                        new CompStatement(new AssignStatement("a", new ArithmeticExpression('+',new ValueExpression(new IntValue(2)),new
                                ArithmeticExpression('*',new ValueExpression(new IntValue(3)), new ValueExpression(new IntValue(5))))),
                                new CompStatement(new AssignStatement("b",new ArithmeticExpression('+',new VariableExpression("a"), new ValueExpression(new
                                        IntValue(1)))), new PrintStatement(new VariableExpression("b"))))));
        ProgramState prg2 = new ProgramState(new AdtStack<>(), new AdtDictionary<>(), new AdtList<>(), ex2, new AdtDictionary<>());
        RepositoryInterface repo2 = new Repository(prg2, "log2.txt");
        Controller controller2 = new Controller(repo2);

        StatementInterface ex3 = new CompStatement(new VariableDeclarationStatement("a", new BoolType()),
                new CompStatement(new VariableDeclarationStatement("v", new IntType()),
                        new CompStatement(new AssignStatement("a", new ValueExpression(new BoolValue(true))),
                                new CompStatement(new IfStatement(new VariableExpression("a"),
                                        new AssignStatement("v", new ValueExpression(new IntValue(2))),
                                        new AssignStatement("v", new ValueExpression(new IntValue(3)))),
                                        new PrintStatement(new VariableExpression("v"))))));
        ProgramState prg3 = new ProgramState(new AdtStack<>(), new AdtDictionary<>(), new AdtList<>(), ex3, new AdtDictionary<>());
        RepositoryInterface repo3 = new Repository(prg3, "log3.txt");
        Controller controller3 = new Controller(repo3);

        StatementInterface ex4 = new CompStatement(new VariableDeclarationStatement("varf", new StringType()),
                new CompStatement(new AssignStatement("varf", new ValueExpression(new StringValue("test.in"))),
                        new CompStatement(new OpenFileStatement(new VariableExpression("varf")), new CompStatement(new VariableDeclarationStatement("varc", new IntType()),
                                new CompStatement(new ReadFileStatement(new VariableExpression("varf"),"varc"),
                                        new CompStatement(new PrintStatement(new VariableExpression("varc")), new CompStatement(new ReadFileStatement(new VariableExpression("varf"), "varc"),
                                                new CompStatement(new PrintStatement(new VariableExpression("varc")), new CloseFileStatement(new VariableExpression("varf"))))))))));
        ProgramState prg4 = new ProgramState(new AdtStack<>(), new AdtDictionary<>(), new AdtList<>(), ex4, new AdtDictionary<>());
        RepositoryInterface repo4 = new Repository(prg4, "log4.txt");
        Controller controller4 = new Controller(repo4);


        StatementInterface ex5 = new CompStatement(new VariableDeclarationStatement("a", new IntType()),
                new CompStatement(new VariableDeclarationStatement("b", new IntType()),
                        new CompStatement(new VariableDeclarationStatement("good", new StringType()),
                        new CompStatement(new VariableDeclarationStatement("bad", new StringType()),
                        new CompStatement(new AssignStatement("good", new ValueExpression(new StringValue("GOOD"))),
                        new CompStatement(new AssignStatement("bad", new ValueExpression(new StringValue("BAD"))),
                        new CompStatement(new AssignStatement("a", new ValueExpression(new IntValue(7))),
                                new CompStatement(new AssignStatement("b", new ValueExpression(new IntValue(6))),
                                        new IfStatement(new RelationalExpression(new VariableExpression("a"),
                                                new VariableExpression("b"), ">"),new PrintStatement(new VariableExpression("good")),
                                                new PrintStatement(new VariableExpression("bad")))))))))));
        ProgramState prg5 = new ProgramState(new AdtStack<>(), new AdtDictionary<>(), new AdtList<>(), ex5, new AdtDictionary<>());
        RepositoryInterface repo5 = new Repository(prg5, "log5.txt");
        Controller controller5 = new Controller(repo5);


        TextMenu menu= new TextMenu();
        menu.addCommand(new RunExample("1", ex1.toString(), controller1));
        menu.addCommand(new RunExample("2", ex2.toString(), controller2));
        menu.addCommand(new RunExample("3",ex3.toString(), controller3));
        menu.addCommand(new RunExample("4",ex4.toString(), controller4));
        menu.addCommand(new RunExample("5", ex5.toString(), controller5));
        menu.addCommand(new ExitCommand("0", "EXIT"));
        menu.show();

    }
}
