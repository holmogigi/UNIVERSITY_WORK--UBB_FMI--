package Repository;
import Exceptions.MyException;
import Model.ProgramState.ProgramState;
import java.io.IOException;
import java.util.List;

public interface RepositoryInterface
{
    List<ProgramState> getProgramList();
    void logProgState(ProgramState prg) throws MyException, IOException;
    void setProgramList(List<ProgramState> prg);
}
