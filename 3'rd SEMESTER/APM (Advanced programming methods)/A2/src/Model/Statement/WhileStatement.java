package Model.Statement;

import Exceptions.MyException;
import Model.ADT.AdtStackInterface;
import Model.Expression.ExpressionInterface;
import Model.ProgramState;
import Model.Type.BoolType;
import Model.Value.BoolValue;
import Model.Value.ValueInterface;

public class WhileStatement implements StatementInterface
{
    private ExpressionInterface exp;
    private StatementInterface statement;

    public WhileStatement(ExpressionInterface expressionInterface, StatementInterface statementInterface)
    {
        this.exp=expressionInterface;
        this.statement=statementInterface;
    }

    @Override
    public ProgramState exe(ProgramState state) throws MyException
    {
        ValueInterface value = this.exp.evaluation(state.get_symTable(), state.getHeap());
        AdtStackInterface<StatementInterface> stack = state.get_exeStack();
        if (!value.get_type().equals(new BoolType()))
            throw new MyException("!ERROR! Value is not of BoolType!");
        BoolValue boolValue = (BoolValue) value;
        if (boolValue.get_value())
        {
            stack.push(this);
            stack.push(statement);
        }
        return state;
    }

    public String toString()
    {
        return String.format("While(%s) {%s} ", this.exp, this.statement);
    }
}
