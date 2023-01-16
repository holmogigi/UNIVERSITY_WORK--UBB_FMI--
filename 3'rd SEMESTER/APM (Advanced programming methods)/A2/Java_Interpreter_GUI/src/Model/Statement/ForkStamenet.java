package Model.Statement;
import Exceptions.MyException;
import Model.ADT.AdtDictionary;
import Model.ADT.AdtDictionaryInterface;
import Model.ADT.AdtStack;
import Model.ADT.AdtStackInterface;
import Model.ProgramState.ProgramState;
import Model.Type.TypeInterface;
import Model.Value.ValueInterface;

import java.util.Map;

public class ForkStamenet implements StatementInterface
{
    private StatementInterface statement;

    public ForkStamenet(StatementInterface statementInterface)
    {
        this.statement=statementInterface;
    }

    @Override
    public AdtDictionaryInterface<String, TypeInterface> typeCheck(AdtDictionaryInterface<String, TypeInterface> typeEnv) throws Exception
    {
        statement.typeCheck(typeEnv.deepCopy());
        return typeEnv;
    }

    @Override
    public ProgramState exe(ProgramState state) throws MyException
    {
        AdtStackInterface<StatementInterface> newStack= new AdtStack<>();
        newStack.push(statement);
        AdtDictionaryInterface<String, ValueInterface> newSymTable= new AdtDictionary<>();
        for(Map.Entry<String,ValueInterface> entry: state.get_symTable().getContent().entrySet())
        {
            newSymTable.put(entry.getKey(), entry.getValue().deepCopy());
        }
        return new ProgramState(newStack ,newSymTable,state.get_out(), state.getFileTable(), state.getHeap());
    }

    public String toString()
    {
        return String.format("Fork(%s)", statement.toString());
    }

    public StatementInterface deepCopy()
    {
        return new ForkStamenet(statement.deepCopy());
    }
}
