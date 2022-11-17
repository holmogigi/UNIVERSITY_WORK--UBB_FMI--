package Model.Expression;
import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.Value.ValueInterface;

public class VariableExpression implements ExpressionInterface
{

    private String id;

    public VariableExpression(String name)
    {
        this.id=name;
    }

    @Override
    public ValueInterface evaluation(AdtDictionaryInterface<String, ValueInterface> table) throws MyException
    {
        return table.lookup(id);
    }

    public String toString()
    {
        return this.id;
    }
}
