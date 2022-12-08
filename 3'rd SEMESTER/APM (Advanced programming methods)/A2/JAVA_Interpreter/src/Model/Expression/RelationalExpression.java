package Model.Expression;

import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.ADT.AdtHeapInterface;
import Model.Type.IntType;
import Model.Value.BoolValue;
import Model.Value.IntValue;
import Model.Value.ValueInterface;

public class RelationalExpression implements ExpressionInterface
{
    private ExpressionInterface expr1;
    private ExpressionInterface expr2;
    private String operand;

    public RelationalExpression(ExpressionInterface exp1, ExpressionInterface exp2, String op)
    {
        this.expr1=exp1;
        this.expr2=exp2;
        this.operand=op;
    }

    @Override
    public ValueInterface evaluation(AdtDictionaryInterface<String, ValueInterface> table, AdtHeapInterface heap) throws MyException
    {
        ValueInterface v1,v2;
        v1=this.expr1.evaluation(table, heap);
        v2=this.expr2.evaluation(table, heap);
        if (v1.get_type().equals(new IntType()) && v2.get_type().equals(new IntType()))
        {
            IntValue value1=(IntValue) v1;
            IntValue value2=(IntValue) v2;
            int int1,int2;
            int1=value1.get_value();
            int2=value2.get_value();
            if (this.operand.equals(">"))
                return new BoolValue(int1 > int2);
            else if (this.operand.equals("<"))
                return new BoolValue(int1 < int2);
            else if (this.operand.equals(">="))
                return new BoolValue(int1 >= int2);
            else if (this.operand.equals("<="))
                return new BoolValue(int1 <= int2);
            else if (this.operand.equals("=="))
                return new BoolValue(int1 == int2);
            else if (this.operand.equals("!="))
                return new BoolValue(int1 != int2);
            else
                throw new MyException("!ERROR! Invalid operand!");
        }
        else throw new MyException("!ERROR! Invalid int type!");
    }

    public String toString()
    {
        return this.expr1.toString() + " " + this.operand + " " + this.expr2.toString();
    }
}
