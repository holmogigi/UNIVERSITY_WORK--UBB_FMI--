package Model.Expression;
import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.ADT.AdtHeapInterface;
import Model.Value.RefValue;
import Model.Value.ValueInterface;
import com.sun.jdi.Value;

public class ReadHeapExpression implements ExpressionInterface
{
    private ExpressionInterface exp;

    public ReadHeapExpression(ExpressionInterface expressionInterface)
    {
        this.exp=expressionInterface;
    }

    @Override
    public ValueInterface evaluation(AdtDictionaryInterface<String, ValueInterface> table, AdtHeapInterface heap) throws MyException
    {
       ValueInterface value=exp.evaluation(table,heap);
       if (!(value instanceof RefValue))
           throw new MyException("!ERROR! Value not RefType!");
       int adr=((RefValue) value).getAddress();
       if (!heap.containsKey(adr))
           throw new MyException("!ERROR! Address not defined!");
        ValueInterface valuee=heap.get(adr);
       return valuee;
    }

    public String toString()
    {
        return String.format("ReadHeap(%s)", this.exp);
    }
}
