package Repository;
import Exceptions.MyException;
import Model.ADT.AdtList;
import Model.ADT.AdtListInterface;
import Model.ProgramState;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Repository implements RepositoryInterface
{
    private List<ProgramState> program;
    private String logFile;

    public Repository(ProgramState state, String logFile) throws IOException {
        this.logFile=logFile;
        this.program=new ArrayList<>();
        this.program.add(state);
        this.empty_logFile();
    }

    public void add(ProgramState state)
    {
        this.program.add(state);
    }

    //Not needed anymore
    @Override
    public List<ProgramState> getProgramList()
    {
        return this.program;
    }

    @Override
    public void logProgState(ProgramState prg) throws MyException, IOException
    {
        PrintWriter logfile;
        logfile=new PrintWriter(new BufferedWriter(new FileWriter(this.logFile,true)));
        logfile.println(prg.toString());
        logfile.close();
    }

    @Override
    public void setProgramList(List<ProgramState> prg)
    {
        this.program=prg;
    }

    public void empty_logFile() throws IOException
    {
        PrintWriter logfile;
        logfile=new PrintWriter(new BufferedWriter(new FileWriter(this.logFile, false)));
        logfile.close();
    }
}

