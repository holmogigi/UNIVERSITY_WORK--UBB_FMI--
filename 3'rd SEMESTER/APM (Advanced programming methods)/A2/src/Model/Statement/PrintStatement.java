package Model.Statement;

import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.ADT.AdtListInterface;
import Model.Expression.ExpressionInterface;
import Model.Expression.ValueExpression;
import Model.ProgramState;
import Model.Value.ValueInterface;

public class PrintStatement implements  StatementInterface
{
    private ExpressionInterface expression;

    public PrintStatement(ExpressionInterface e)
    {
        this.expression=e;
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

    public String toString()
    {
        return " print("+ this.expression.toString() + ")";
    }
}
