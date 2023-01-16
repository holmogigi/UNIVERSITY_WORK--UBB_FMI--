package Model.Statement;
import Exceptions.MyException;
import Model.Expression.ExpressionInterface;
import Model.ProgramState.ProgramState;
import Model.ADT.AdtDictionaryInterface;
import Model.ADT.AdtStackInterface;
import Model.Type.TypeInterface;
import Model.Value.ValueInterface;

public class AssignStatement implements StatementInterface
{
    private String id;
    private ExpressionInterface expression;

    public AssignStatement(String id, ExpressionInterface expr)
    {
        this.id=id;
        this.expression=expr;
    }

    @Override
    public AdtDictionaryInterface<String, TypeInterface> typeCheck(AdtDictionaryInterface<String, TypeInterface> typeEnv) throws Exception
    {
        TypeInterface typeVar = typeEnv.lookup(id);
        TypeInterface typeExpr = expression.typeCheck(typeEnv);
        if (typeVar.equals(typeExpr))
            return typeEnv;
        else
            throw new Exception("Assignment: right hand side and left hand side have different types.");
    }

    @Override
    public ProgramState exe(ProgramState state) throws MyException
    {
        AdtStackInterface<StatementInterface> exeStack= state.get_exeStack();
        AdtDictionaryInterface<String, ValueInterface> symTable=state.get_symTable();
        if (symTable.isDefined(this.id))
        {
            ValueInterface value=this.expression.evaluation(symTable, state.getHeap());
            TypeInterface typeId= (symTable.lookup(this.id)).get_type();
            if ((value.get_type()).equals(typeId))
                symTable.update(this.id,value);
            else
                throw new MyException("!ERROR! Declared variable type and expression does not match!");
        }
        else throw new MyException("!ERROR! Variable not declared before!");
        return state;
    }

    @Override
    public StatementInterface deepCopy()
    {
        return new AssignStatement(id, expression.deepCopy());
    }

    public String toString()
    {
        return this.id + " = " + this.expression.toString();
    }
}
