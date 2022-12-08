package Repository;
import Exceptions.MyException;
import Model.ADT.AdtList;
import Model.ADT.AdtListInterface;
import Model.ProgramState;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Repository implements RepositoryInterface
{
    private AdtListInterface<ProgramState> program;
    private int curr;
    private String logFile;

    public Repository(ProgramState state, String logFile)
    {
        this.curr=0;
        this.program=new AdtList<ProgramState>();
        this.program.add(state);
        this.logFile=logFile;
    }

    public void add(ProgramState state)
    {
        this.program.add(state);
    }

    @Override
    public ProgramState get_prgState()
    {
        return this.program.get(curr);
    }

    @Override
    public void logProgState() throws MyException, IOException
    {
        PrintWriter logfile;
        logfile=new PrintWriter(new BufferedWriter(new FileWriter(this.logFile,true)));
        logfile.println(this.program.get(0).toString());
        logfile.close();
    }

    public void empty_logFile() throws IOException
    {
        PrintWriter logfile;
        logfile=new PrintWriter(new BufferedWriter(new FileWriter(this.logFile, false)));
        logfile.close();
    }
}

