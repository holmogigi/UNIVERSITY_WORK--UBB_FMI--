package Model.Expression;
import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.ADT.AdtHeapInterface;
import Model.Type.TypeInterface;
import Model.Value.ValueInterface;

public class VariableExpression implements ExpressionInterface
{

    private String id;

    public VariableExpression(String name)
    {
        this.id=name;
    }

    @Override
    public TypeInterface typeCheck(AdtDictionaryInterface<String, TypeInterface> typeEnv) throws Exception
    {
        return typeEnv.lookup(id);
    }

    @Override
    public ValueInterface evaluation(AdtDictionaryInterface<String, ValueInterface> table, AdtHeapInterface heap) throws MyException
    {
        return table.lookup(id);
    }

    @Override
    public ExpressionInterface deepCopy()
    {
        return new VariableExpression(id);
    }

    public String toString()
    {
        return this.id;
    }
}
