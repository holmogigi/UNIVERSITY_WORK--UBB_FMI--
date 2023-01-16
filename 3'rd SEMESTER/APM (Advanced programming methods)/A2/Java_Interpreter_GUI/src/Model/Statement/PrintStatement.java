package Model.Statement;

import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.ADT.AdtListInterface;
import Model.Expression.ExpressionInterface;
import Model.ProgramState.ProgramState;
import Model.Type.TypeInterface;
import Model.Value.ValueInterface;

public class PrintStatement implements  StatementInterface
{
    private ExpressionInterface expression;

    public PrintStatement(ExpressionInterface e)
    {
        this.expression=e;
    }

    @Override
    public AdtDictionaryInterface<String, TypeInterface> typeCheck(AdtDictionaryInterface<String, TypeInterface> typeEnv) throws Exception {
        this.expression.typeCheck(typeEnv);
        return typeEnv;
    }

    @Override
    public ProgramState exe(ProgramState state) throws MyException
    {
        AdtListInterface<ValueInterface> out_list=state.get_out();
        AdtDictionaryInterface<String, ValueInterface> symTable=state.get_symTable();
        ValueInterface val=this.expression.evaluation(symTable, state.getHeap());
        out_list.add(val);
        return state;
    }

    @Override
    public StatementInterface deepCopy()
    {
        return new PrintStatement(expression.deepCopy());
    }

    public String toString()
    {
        return " print("+ this.expression.toString() + ")";
    }
}
