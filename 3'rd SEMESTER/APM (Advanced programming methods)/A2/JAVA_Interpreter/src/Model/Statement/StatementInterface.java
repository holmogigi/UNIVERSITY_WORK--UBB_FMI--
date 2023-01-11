package Model.Statement;
import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.ProgramState;
import Model.Type.TypeInterface;

public interface StatementInterface
{
    AdtDictionaryInterface<String, TypeInterface> typeCheck(AdtDictionaryInterface<String, TypeInterface> typeEnv) throws Exception;
    ProgramState exe(ProgramState state) throws MyException;
    StatementInterface deepCopy();
}
