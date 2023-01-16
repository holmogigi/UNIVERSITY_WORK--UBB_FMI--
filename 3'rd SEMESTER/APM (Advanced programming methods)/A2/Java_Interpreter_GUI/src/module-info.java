module gui {
    requires javafx.controls;
    requires javafx.fxml;

    opens gui to javafx.fxml;
    exports gui;

    exports Controller;
    opens Controller to javafx.fxml;

    exports Exceptions;
    opens Exceptions to javafx.fxml;

    exports  Model.Expression;
    opens Model.Expression to javafx.fxml;

    exports Model.ProgramState;
    opens Model.ProgramState to javafx.fxml;

    exports Model.Statement;
    opens Model.Statement to javafx.fxml;

    exports Model.Type;
    opens Model.Type to javafx.fxml;

    exports Model.ADT;
    opens Model.ADT to javafx.fxml;

    exports Model.Value;
    opens Model.Value to javafx.fxml;

    exports Repository;
    opens Repository to javafx.fxml;
}