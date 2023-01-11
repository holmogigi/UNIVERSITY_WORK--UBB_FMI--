package Model.Statement;
import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.ADT.AdtStackInterface;
import Model.Expression.ExpressionInterface;
import Model.ProgramState;
import Model.Type.BoolType;
import Model.Type.TypeInterface;
import Model.Value.BoolValue;
import Model.Value.ValueInterface;

public class IfStatement implements StatementInterface
{
    private ExpressionInterface expression;
    private StatementInterface then_statement;
    private StatementInterface else_statement;

    public IfStatement(ExpressionInterface e, StatementInterface then_s, StatementInterface else_s)
    {
        this.expression=e;
        this.then_statement=then_s;
        this.else_statement=else_s;
    }

    @Override
    public AdtDictionaryInterface<String, TypeInterface> typeCheck(AdtDictionaryInterface<String, TypeInterface> typeEnv) throws Exception
    {
        TypeInterface type=expression.typeCheck(typeEnv);
        if (type.equals(new BoolType()))
        {
            this.then_statement.typeCheck(typeEnv.deepCopy());
            this.else_statement.typeCheck(typeEnv.deepCopy());
            return typeEnv;
        }
        else
            throw new MyException("!ERROR! Non bool expresion in if!");
    }

    @Override
    public ProgramState exe(ProgramState state) throws MyException
    {
        AdtStackInterface<StatementInterface> stack=state.get_exeStack();
        ValueInterface condition=this.expression.evaluation(state.get_symTable(), state.getHeap());
        if (!(condition.get_type() instanceof BoolType))
            throw new MyException("!ERROR! Condition not bool!");
        else
        {
            BoolValue bool_cond=(BoolValue)condition;
            if (bool_cond.get_value())
                stack.push(then_statement);
            else
                stack.push(else_statement);
        }
        return state;
    }

    @Override
    public StatementInterface deepCopy()
    {
        return new IfStatement(expression.deepCopy(), then_statement.deepCopy(), else_statement.deepCopy());
    }

    public String toString()
    {
        return "(IF("+ this.expression.toString()+") THEN (" +this.then_statement.toString() +") ELSE ("+this.else_statement.toString()+"))";
    }
}
