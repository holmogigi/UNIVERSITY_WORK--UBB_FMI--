package Repository;
import Exceptions.MyException;
import Model.ProgramState;
import java.io.IOException;

public interface RepositoryInterface
{
    ProgramState get_prgState();
    void logProgState() throws MyException, IOException;
}
