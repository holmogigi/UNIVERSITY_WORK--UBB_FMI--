package Model.Expression;
import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.Value.ValueInterface;

public interface ExpressionInterface
{
    ValueInterface evaluation(AdtDictionaryInterface<String, ValueInterface> table) throws MyException;

}
