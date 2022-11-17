package Model.Expression;
import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.Value.ValueInterface;
import Model.Value.IntValue;

public class ValueExpression implements ExpressionInterface
{
    private ValueInterface value;

    public ValueExpression(ValueInterface val)
    {
        this.value=val;
    }

    @Override
    public ValueInterface evaluation(AdtDictionaryInterface<String, ValueInterface> table) throws MyException
    {
        return this.value;
    }

    public String toString()
    {
        return this.value.toString();
    }
}
