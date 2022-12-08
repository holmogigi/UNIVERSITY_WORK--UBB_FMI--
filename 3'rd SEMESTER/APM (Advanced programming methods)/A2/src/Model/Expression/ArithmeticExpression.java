package Model.Expression;
import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.ADT.AdtHeapInterface;
import Model.Value.ValueInterface;
import Model.Type.IntType;
import Model.Value.IntValue;

public class ArithmeticExpression implements ExpressionInterface
{
    private ExpressionInterface exp1;
    private ExpressionInterface exp2;
    private int operation;

    public ArithmeticExpression(char operand, ExpressionInterface exp1, ExpressionInterface exp2)
    {
        this.exp1=exp1;
        this.exp2=exp2;
        if (operand == '+')
            this.operation=1;
        else if (operand == '-')
            this.operation=2;
        else if (operand == '*')
            this.operation=3;
        else if (operand == '/')
            this.operation=4;
    }


    @Override
    public ValueInterface evaluation(AdtDictionaryInterface<String, ValueInterface> table, AdtHeapInterface heap) throws MyException
    {
        ValueInterface value1, value2;
        value1=this.exp1.evaluation(table, heap);
        if (value1.get_type().equals(new IntType()))
        {
            value2=this.exp2.evaluation(table, heap);
            if (value2.get_type().equals(new IntType()))
            {
                IntValue int1= (IntValue) value1;
                IntValue int2= (IntValue) value2;
                int n1,n2;
                n1=int1.get_value();
                n2=int2.get_value();
                if (this.operation==1)
                    return new IntValue(n1+n2);
                else if (this.operation==2)
                    return new IntValue(n1-n2);
                else if (this.operation==3)
                    return new IntValue(n1*n2);
                else if (this.operation==4)
                {
                    if (n2==0)
                        throw new MyException("!ERROR! Division by zero!");
                    else
                        return new IntValue(n1/n2);
                }
            }
            else
                throw new MyException("!ERROR! Second operand not integer!");
        }
        else
            throw new MyException("!ERROR! First operand not integer!");

        return null;
    }

    public String toString()
    {
        if (this.operation==1)
            return this.exp1 + "+" + this.exp2;
        else if(this.operation==2)
            return this.exp1 + "-" + this.exp2;
        else if (this.operation==3)
            return this.exp1 + "*" + this.exp2;
        else
            return this.exp1 + "/" + this.exp2;
    }

}
