package Model.Statement;
import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.ADT.AdtStackInterface;
import Model.ProgramState;

public class CompStatement implements  StatementInterface
{
    private StatementInterface first;
    private StatementInterface second;

    public CompStatement(StatementInterface f, StatementInterface s)
    {
        this.first=f;
        this.second=s;
    }

    public StatementInterface getFirst()
    {
        return this.first;
    }

    public StatementInterface getSecond()
    {
        return this.second;
    }

    @Override
    public ProgramState exe(ProgramState state) throws MyException
    {
        AdtStackInterface<StatementInterface> stack= state.get_exeStack();
        stack.push(second);
        stack.push(first);
        return state;
    }


    public String toString()
    {
        return "(" +  first.toString() + ";" + second.toString() + ")";
    }
}
