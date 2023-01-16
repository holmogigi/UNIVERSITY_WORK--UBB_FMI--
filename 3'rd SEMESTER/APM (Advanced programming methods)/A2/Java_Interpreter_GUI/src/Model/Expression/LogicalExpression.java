package Model.Expression;
import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.ADT.AdtHeapInterface;
import Model.Type.TypeInterface;
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
    public TypeInterface typeCheck(AdtDictionaryInterface<String, TypeInterface> typeEnv) throws Exception
    {
        TypeInterface type1, type2;
        type1=exp1.typeCheck(typeEnv);
        type2=exp2.typeCheck(typeEnv);
        if (type1.equals(new BoolType()))
        {
            if (type2.equals(new BoolType()))
            {
                return new BoolType();
            }else
                throw new Exception("!ERROR! Second operand not bool!");
        }else
            throw new Exception("!EROOR! First operand not bool!");
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

    @Override
    public ExpressionInterface deepCopy()
    {
        if (this.operation==1)
            return new LogicalExpression("and", exp1.deepCopy(), exp2.deepCopy());
        else
            return new LogicalExpression("or", exp1.deepCopy(), exp2.deepCopy());
    }
}
