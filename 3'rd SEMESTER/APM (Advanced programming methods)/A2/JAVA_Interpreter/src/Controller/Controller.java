package Controller;
import Exceptions.MyException;
import Model.ADT.AdtStackInterface;
import Model.ProgramState;
import Model.Statement.StatementInterface;
import Repository.RepositoryInterface;
import javax.imageio.IIOException;
import java.io.IOException;

public class Controller
{
    private RepositoryInterface repo;

    public Controller(RepositoryInterface rep)
    {
        this.repo=rep;
    }

    public ProgramState single_step(ProgramState state) throws MyException
    {
        AdtStackInterface<StatementInterface> stackexe= state.get_exeStack();
        if (stackexe.isEmpty())
            throw new MyException("!ERROR! Program exe stack empty!");
        StatementInterface curr_statement=stackexe.pop();
        return curr_statement.exe(state);
    }

    public void all_steps() throws MyException, IOException
    {
        ProgramState program=this.repo.get_prgState();
        this.repo.logProgState();
        while(!program.get_exeStack().isEmpty())
        {
            single_step(program);
            this.repo.logProgState();
            System.out.println(program.toString());
        }
    }

}
