package Model.Expression;
import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.ADT.AdtHeapInterface;
import Model.Type.TypeInterface;
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
    public TypeInterface typeCheck(AdtDictionaryInterface<String, TypeInterface> typeEnv) throws Exception
    {
        return value.get_type();
    }

    @Override
    public ValueInterface evaluation(AdtDictionaryInterface<String, ValueInterface> table, AdtHeapInterface heap) throws MyException
    {
        return this.value;
    }

    @Override
    public ExpressionInterface deepCopy()
    {
        return new ValueExpression(value.deepCopy());
    }

    public String toString()
    {
        return this.value.toString();
    }
}
