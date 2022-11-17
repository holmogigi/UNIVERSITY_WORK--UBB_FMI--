package Model.Statement;
import Exceptions.MyException;
import Model.ProgramState;

public interface StatementInterface
{
    ProgramState exe(ProgramState state) throws MyException;

}
