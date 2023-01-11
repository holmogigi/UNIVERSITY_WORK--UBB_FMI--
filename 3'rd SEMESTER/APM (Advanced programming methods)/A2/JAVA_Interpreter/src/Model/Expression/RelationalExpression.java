package Model.Expression;

import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.ADT.AdtHeapInterface;
import Model.Type.BoolType;
import Model.Type.IntType;
import Model.Type.TypeInterface;
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
    public TypeInterface typeCheck(AdtDictionaryInterface<String, TypeInterface> typeEnv) throws Exception
    {
        TypeInterface type1,type2;
        type1=expr1.typeCheck(typeEnv);
        type2=expr2.typeCheck(typeEnv);
        if (type1.equals(new IntType()))
        {
            if (type2.equals(new IntType()))
            {
                return new BoolType();
            }else
                throw new Exception("!ERROR! Second operand not int!");
        }else
            throw new Exception("!ERROR! First operand not int!");
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

    @Override
    public ExpressionInterface deepCopy()
    {
        return new RelationalExpression(expr1.deepCopy(), expr2.deepCopy(), operand);
    }

    public String toString()
    {
        return this.expr1.toString() + " " + this.operand + " " + this.expr2.toString();
    }
}
