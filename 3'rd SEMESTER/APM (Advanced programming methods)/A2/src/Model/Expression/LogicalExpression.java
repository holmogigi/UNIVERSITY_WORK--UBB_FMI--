package Model.Expression;
import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.ADT.AdtHeapInterface;
import Model.Value.ValueInterface;
import Model.Value.BoolValue;
import Model.Type.BoolType;


public class LogicalExpression implements ExpressionInterface
{
    private ExpressionInterface exp1;
    private ExpressionInterface exp2;
    private int operation;

    public LogicalExpression(String operand, ExpressionInterface exp1, ExpressionInterface exp2)
    {
        this.exp1=exp1;
        this.exp2=exp2;
        if (operand.equals("and"))
            this.operation=1;
        else
            this.operation=2;
    }

    @Override
    public ValueInterface evaluation(AdtDictionaryInterface<String, ValueInterface> table, AdtHeapInterface heap) throws MyException
    {
        ValueInterface value1, value2;
        value1=this.exp1.evaluation(table, heap);
        if (value1.get_type() instanceof BoolType)
        {
            value2=this.exp2.evaluation(table, heap);
            if (value2.get_type() instanceof BoolType)
            {
                BoolValue b1,b2;
                b1 = (BoolValue)value1;
                b2= (BoolValue) value2;
                boolean bool1,bool2;
                bool1=b1.get_value();
                bool2=b2.get_value();
                if (this.operation==1)
                    return new BoolValue(bool1 && bool2);
                else
                    return new BoolValue(bool1 || bool2);
            }
            else
                throw new MyException("!ERROR! Second operand not bool!");
        }
        else
            throw new MyException("!ERROR! First operand not bool!");

    }


    public String toString()
    {
        if (this.operation==1)
            return this.exp1.toString() + "and" + this.exp2.toString();
        else
            return this.exp2.toString() + "or" + this.exp2.toString();
    }
}
