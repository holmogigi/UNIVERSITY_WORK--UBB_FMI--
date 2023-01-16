package gui;

import Controller.Controller;
import Exceptions.MyException;
import Model.ADT.AdtDictionary;
import Model.ADT.AdtHeap;
import Model.ADT.AdtList;
import Model.ADT.AdtStack;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import Model.Expression.*;
import Model.ProgramState.ProgramState;
import Model.Statement.*;
import Model.Type.BoolType;
import Model.Type.IntType;
import Model.Type.RefType;
import Model.Type.StringType;
import Model.Value.BoolValue;
import Model.Value.IntValue;
import Model.Value.StringValue;
import Repository.Repository;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ProgramChooserController {
    private ProgramExecutorController programExecutorController;

    public void setProgramExecutorController(ProgramExecutorController programExecutorController) {
        this.programExecutorController = programExecutorController;
    }
    @FXML
    private ListView<StatementInterface> programsListView;

    @FXML
    private Button displayButton;

    @FXML
    public void initialize() {
        programsListView.setItems(getAllStatements());
        programsListView.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
    }

    @FXML
    private void displayProgram(ActionEvent actionEvent) {
        StatementInterface selectedStatement = programsListView.getSelectionModel().getSelectedItem();
        if (selectedStatement == null) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error encountered!");
            alert.setContentText("No statement selected!");
            alert.showAndWait();
        } else {
            int id = programsListView.getSelectionModel().getSelectedIndex();
            try {
                selectedStatement.typeCheck(new AdtDictionary<>());
                ProgramState programState = new ProgramState(new AdtStack<>(), new AdtDictionary<>(), new AdtList<>(), new AdtDictionary<>(), new AdtHeap(), selectedStatement);
                Repository repository = new Repository(programState, "log" + (id + 1) + ".txt");
                Controller controller = new Controller(repository);
                programExecutorController.setController(controller);
            } catch (MyException | IOException exception) {
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("Error encountered!");
                alert.setContentText(exception.getMessage());
                alert.showAndWait();
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }
    }

    @FXML
    private ObservableList<StatementInterface> getAllStatements() {
        List<StatementInterface> allStatements = new ArrayList<>();

        StatementInterface ex1 = new CompStatement(new VariableDeclarationStatement("v", new IntType()),
                new CompStatement(new AssignStatement("v", new ValueExpression(new IntValue(2))),
                        new PrintStatement(new VariableExpression("v"))));
        allStatements.add(ex1);

        StatementInterface ex2 = new CompStatement(new VariableDeclarationStatement("a",new IntType()),
                new CompStatement(new VariableDeclarationStatement("b",new IntType()),
                        new CompStatement(new AssignStatement("a", new ArithmeticExpression('+',new ValueExpression(new IntValue(2)),new
                                ArithmeticExpression('*',new ValueExpression(new IntValue(3)), new ValueExpression(new IntValue(5))))),
                                new CompStatement(new AssignStatement("b",new ArithmeticExpression('+',new VariableExpression("a"), new ValueExpression(new
                                        IntValue(1)))), new PrintStatement(new VariableExpression("b"))))));
        allStatements.add(ex2);

        StatementInterface ex3 = new CompStatement(new VariableDeclarationStatement("a", new BoolType()),
                new CompStatement(new VariableDeclarationStatement("v", new IntType()),
                        new CompStatement(new AssignStatement("a", new ValueExpression(new BoolValue(true))),
                                new CompStatement(new IfStatement(new VariableExpression("a"),
                                        new AssignStatement("v", new ValueExpression(new IntValue(2))),
                                        new AssignStatement("v", new ValueExpression(new IntValue(3)))),
                                        new PrintStatement(new VariableExpression("v"))))));
        allStatements.add(ex3);

        StatementInterface ex4 = new CompStatement(new VariableDeclarationStatement("varf", new StringType()),
                new CompStatement(new AssignStatement("varf", new ValueExpression(new StringValue("test.in"))),
                        new CompStatement(new OpenFileStatement(new VariableExpression("varf")), new CompStatement(new VariableDeclarationStatement("varc", new IntType()),
                                new CompStatement(new ReadFileStatement(new VariableExpression("varf"),"varc"),
                                        new CompStatement(new PrintStatement(new VariableExpression("varc")), new CompStatement(new ReadFileStatement(new VariableExpression("varf"), "varc"),
                                                new CompStatement(new PrintStatement(new VariableExpression("varc")), new CloseFileStatement(new VariableExpression("varf"))))))))));
        allStatements.add(ex4);

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
        allStatements.add(ex5);

        StatementInterface ex6 = new CompStatement(new VariableDeclarationStatement("v", new RefType(new IntType())),
                new CompStatement(new NewStatement("v", new ValueExpression(new IntValue(20))),
                        new CompStatement(new VariableDeclarationStatement("a", new RefType(new RefType(new IntType()))),
                                new CompStatement(new NewStatement("a", new VariableExpression("v")),
                                        new CompStatement(new PrintStatement(new VariableExpression("v")), new PrintStatement(new VariableExpression("a")))))));
        allStatements.add(ex6);

        StatementInterface ex7 = new CompStatement(new VariableDeclarationStatement("v", new RefType(new IntType())),
                new CompStatement(new NewStatement("v", new ValueExpression(new IntValue(20))),
                        new CompStatement(new VariableDeclarationStatement("a", new RefType(new RefType(new IntType()))),
                                new CompStatement(new NewStatement("a", new VariableExpression("v")),
                                        new CompStatement(new PrintStatement(new ReadHeapExpression(new VariableExpression("v"))),
                                                new PrintStatement(new ArithmeticExpression('+',new ReadHeapExpression(new ReadHeapExpression(new VariableExpression("a"))), new ValueExpression(new IntValue(5)))))))));
        allStatements.add(ex7);

        StatementInterface ex8 = new CompStatement(new VariableDeclarationStatement("v", new RefType(new IntType())),
                new CompStatement(new NewStatement("v", new ValueExpression(new IntValue(20))),
                        new CompStatement( new PrintStatement(new ReadHeapExpression(new VariableExpression("v"))),
                                new CompStatement(new WriteHeapStatement("v", new ValueExpression(new IntValue(30))),
                                        new PrintStatement(new ArithmeticExpression('+', new ReadHeapExpression(new VariableExpression("v")), new ValueExpression(new IntValue(5))))))));
        allStatements.add(ex8);

        StatementInterface ex9 = new CompStatement(new VariableDeclarationStatement("v", new IntType()),
                new CompStatement(new AssignStatement("v", new ValueExpression(new IntValue(4))),
                        new CompStatement(new WhileStatement(new RelationalExpression(new VariableExpression("v"),new ValueExpression(new IntValue(0)), ">"),
                                new CompStatement(new PrintStatement(new VariableExpression("v")), new AssignStatement("v", new ArithmeticExpression('-', new VariableExpression("v"), new ValueExpression(new IntValue(1)))))),
                                new PrintStatement(new VariableExpression("v")))));
        allStatements.add(ex9);

        StatementInterface ex10 = new CompStatement(new VariableDeclarationStatement("v", new IntType()),
                new CompStatement(new VariableDeclarationStatement("a", new RefType(new IntType())),
                        new CompStatement(new AssignStatement("v", new ValueExpression(new IntValue(10))),
                                new CompStatement(new NewStatement("a", new ValueExpression(new IntValue(22))),
                                        new CompStatement(new ForkStamenet(new CompStatement(new WriteHeapStatement("a", new ValueExpression(new IntValue(30))),
                                                new CompStatement(new AssignStatement("v", new ValueExpression(new IntValue(32))),
                                                        new CompStatement(new PrintStatement(new VariableExpression("v")), new PrintStatement(new ReadHeapExpression(new VariableExpression("a"))))))),
                                                new CompStatement(new PrintStatement(new VariableExpression("v")), new PrintStatement(new ReadHeapExpression(new VariableExpression("a")))))))));
        allStatements.add(ex10);

        return FXCollections.observableArrayList(allStatements);
    }
}