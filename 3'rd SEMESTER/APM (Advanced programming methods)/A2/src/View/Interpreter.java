package View;
import Controller.Controller;
import Exceptions.MyException;
import Model.ADT.*;
import Model.Expression.*;
import Model.ProgramState;
import Model.Statement.*;
import Model.Type.BoolType;
import Model.Type.IntType;
import Model.Type.RefType;
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
        ProgramState prg1 = new ProgramState(new AdtStack<>(), new AdtDictionary<>(), new AdtList<>(), ex1, new AdtDictionary<>(), new AdtHeap());
        RepositoryInterface repo1 = new Repository(prg1, "log1.txt");
        Controller controller1 = new Controller(repo1);

        StatementInterface ex2 = new CompStatement(new VariableDeclarationStatement("a",new IntType()),
                new CompStatement(new VariableDeclarationStatement("b",new IntType()),
                        new CompStatement(new AssignStatement("a", new ArithmeticExpression('+',new ValueExpression(new IntValue(2)),new
                                ArithmeticExpression('*',new ValueExpression(new IntValue(3)), new ValueExpression(new IntValue(5))))),
                                new CompStatement(new AssignStatement("b",new ArithmeticExpression('+',new VariableExpression("a"), new ValueExpression(new
                                        IntValue(1)))), new PrintStatement(new VariableExpression("b"))))));
        ProgramState prg2 = new ProgramState(new AdtStack<>(), new AdtDictionary<>(), new AdtList<>(), ex2, new AdtDictionary<>(), new AdtHeap());
        RepositoryInterface repo2 = new Repository(prg2, "log2.txt");
        Controller controller2 = new Controller(repo2);

        StatementInterface ex3 = new CompStatement(new VariableDeclarationStatement("a", new BoolType()),
                new CompStatement(new VariableDeclarationStatement("v", new IntType()),
                        new CompStatement(new AssignStatement("a", new ValueExpression(new BoolValue(true))),
                                new CompStatement(new IfStatement(new VariableExpression("a"),
                                        new AssignStatement("v", new ValueExpression(new IntValue(2))),
                                        new AssignStatement("v", new ValueExpression(new IntValue(3)))),
                                        new PrintStatement(new VariableExpression("v"))))));
        ProgramState prg3 = new ProgramState(new AdtStack<>(), new AdtDictionary<>(), new AdtList<>(), ex3, new AdtDictionary<>(), new AdtHeap());
        RepositoryInterface repo3 = new Repository(prg3, "log3.txt");
        Controller controller3 = new Controller(repo3);

        StatementInterface ex4 = new CompStatement(new VariableDeclarationStatement("varf", new StringType()),
                new CompStatement(new AssignStatement("varf", new ValueExpression(new StringValue("test.in"))),
                        new CompStatement(new OpenFileStatement(new VariableExpression("varf")), new CompStatement(new VariableDeclarationStatement("varc", new IntType()),
                                new CompStatement(new ReadFileStatement(new VariableExpression("varf"),"varc"),
                                        new CompStatement(new PrintStatement(new VariableExpression("varc")), new CompStatement(new ReadFileStatement(new VariableExpression("varf"), "varc"),
                                                new CompStatement(new PrintStatement(new VariableExpression("varc")), new CloseFileStatement(new VariableExpression("varf"))))))))));
        ProgramState prg4 = new ProgramState(new AdtStack<>(), new AdtDictionary<>(), new AdtList<>(), ex4, new AdtDictionary<>(), new AdtHeap());
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
        ProgramState prg5 = new ProgramState(new AdtStack<>(), new AdtDictionary<>(), new AdtList<>(), ex5, new AdtDictionary<>(), new AdtHeap());
        RepositoryInterface repo5 = new Repository(prg5, "log5.txt");
        Controller controller5 = new Controller(repo5);

        StatementInterface ex6 = new CompStatement(new VariableDeclarationStatement("v", new RefType(new IntType())),
                new CompStatement(new NewStatement("v", new ValueExpression(new IntValue(20))),
                        new CompStatement(new VariableDeclarationStatement("a", new RefType(new RefType(new IntType()))),
                                new CompStatement(new NewStatement("a", new VariableExpression("v")),
                                        new CompStatement(new PrintStatement(new VariableExpression("v")), new PrintStatement(new VariableExpression("a")))))));
        ProgramState prg6 = new ProgramState(new AdtStack<>(), new AdtDictionary<>(), new AdtList<>(), ex6, new AdtDictionary<>(), new AdtHeap());
        RepositoryInterface repo6 = new Repository(prg6, "log6.txt");
        Controller controller6 = new Controller(repo6);

        StatementInterface ex7 = new CompStatement(new VariableDeclarationStatement("v", new RefType(new IntType())),
                new CompStatement(new NewStatement("v", new ValueExpression(new IntValue(20))),
                        new CompStatement(new VariableDeclarationStatement("a", new RefType(new RefType(new IntType()))),
                                new CompStatement(new NewStatement("a", new VariableExpression("v")),
                                        new CompStatement(new PrintStatement(new ReadHeapExpression(new VariableExpression("v"))),
                                                new PrintStatement(new ArithmeticExpression('+',new ReadHeapExpression(new ReadHeapExpression(new VariableExpression("a"))), new ValueExpression(new IntValue(5)))))))));
        ProgramState prg7 = new ProgramState(new AdtStack<>(), new AdtDictionary<>(), new AdtList<>(), ex7, new AdtDictionary<>(), new AdtHeap());
        RepositoryInterface repo7 = new Repository(prg7, "log7.txt");
        Controller controller7 = new Controller(repo7);

        StatementInterface ex8 = new CompStatement(new VariableDeclarationStatement("v", new RefType(new IntType())),
                new CompStatement(new NewStatement("v", new ValueExpression(new IntValue(20))),
                        new CompStatement( new PrintStatement(new ReadHeapExpression(new VariableExpression("v"))),
                                new CompStatement(new WriteHeapStatement("v", new ValueExpression(new IntValue(30))),
                                        new PrintStatement(new ArithmeticExpression('+', new ReadHeapExpression(new VariableExpression("v")), new ValueExpression(new IntValue(5))))))));
        ProgramState prg8 = new ProgramState(new AdtStack<>(), new AdtDictionary<>(), new AdtList<>(), ex8, new AdtDictionary<>(), new AdtHeap());
        RepositoryInterface repo8 = new Repository(prg8, "log8.txt");
        Controller controller8 = new Controller(repo8);

        StatementInterface ex9 = new CompStatement(new VariableDeclarationStatement("v", new IntType()),
                new CompStatement(new AssignStatement("v", new ValueExpression(new IntValue(4))),
                        new CompStatement(new WhileStatement(new RelationalExpression(new VariableExpression("v"),new ValueExpression(new IntValue(0)), ">"),
                                new CompStatement(new PrintStatement(new VariableExpression("v")), new AssignStatement("v", new ArithmeticExpression('-', new VariableExpression("v"), new ValueExpression(new IntValue(1)))))),
                                new PrintStatement(new VariableExpression("v")))));
        ProgramState prg9 = new ProgramState(new AdtStack<>(), new AdtDictionary<>(), new AdtList<>(), ex9, new AdtDictionary<>(), new AdtHeap());
        RepositoryInterface repo9 = new Repository(prg9, "log9.txt");
        Controller controller9 = new Controller(repo9);

        TextMenu menu= new TextMenu();
        menu.addCommand(new RunExample("1", ex1.toString(), controller1));
        menu.addCommand(new RunExample("2", ex2.toString(), controller2));
        menu.addCommand(new RunExample("3",ex3.toString(), controller3));
        menu.addCommand(new RunExample("4",ex4.toString(), controller4));
        menu.addCommand(new RunExample("5", ex5.toString(), controller5));
        menu.addCommand(new RunExample("6", ex6.toString(), controller6));
        menu.addCommand(new RunExample("7", ex7.toString(), controller7));
        menu.addCommand(new RunExample("8", ex8.toString(), controller8));
        menu.addCommand(new RunExample("9", ex9.toString(), controller9));
        menu.addCommand(new ExitCommand("0", "EXIT"));
        menu.show();

    }
}
