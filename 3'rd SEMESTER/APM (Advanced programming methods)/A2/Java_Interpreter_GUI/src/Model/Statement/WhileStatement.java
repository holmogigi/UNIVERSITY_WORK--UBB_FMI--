package Model.Statement;

import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.ADT.AdtStackInterface;
import Model.Expression.ExpressionInterface;
import Model.ProgramState.ProgramState;
import Model.Type.BoolType;
import Model.Type.TypeInterface;
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
    public AdtDictionaryInterface<String, TypeInterface> typeCheck(AdtDictionaryInterface<String, TypeInterface> typeEnv) throws Exception {
        TypeInterface type= exp.typeCheck(typeEnv);
        if (type.equals(new BoolType()))
        {
            statement.typeCheck(typeEnv.deepCopy());
            return typeEnv;
        }else
            throw new MyException("!ERROR! While condition not bool!");
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

    @Override
    public StatementInterface deepCopy()
    {
        return new WhileStatement(exp.deepCopy(), statement.deepCopy());
    }

    public String toString()
    {
        return String.format("While(%s) {%s} ", this.exp, this.statement);
    }
}
