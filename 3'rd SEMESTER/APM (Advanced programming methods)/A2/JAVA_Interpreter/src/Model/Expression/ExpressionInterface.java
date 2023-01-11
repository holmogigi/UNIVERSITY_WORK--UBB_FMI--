package Model.Expression;
import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.ADT.AdtHeapInterface;
import Model.Value.ValueInterface;
import Model.Type.TypeInterface;

public interface ExpressionInterface
{
    TypeInterface typeCheck(AdtDictionaryInterface<String, TypeInterface> typeEnv) throws Exception;
    ValueInterface evaluation(AdtDictionaryInterface<String, ValueInterface> table, AdtHeapInterface heap) throws MyException;
    ExpressionInterface deepCopy();
}
