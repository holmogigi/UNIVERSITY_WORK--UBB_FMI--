package Model.Statement;
import Exceptions.MyException;
import Model.ADT.AdtStack;
import Model.Expression.ExpressionInterface;
import Model.ProgramState;
import Model.ADT.AdtListInterface;
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
    public ProgramState exe(ProgramState state) throws MyException
    {
        AdtStackInterface<StatementInterface> exeStack= state.get_exeStack();
        AdtDictionaryInterface<String, ValueInterface> symTable=state.get_symTable();
        if (symTable.isDefined(this.id))
        {
            ValueInterface value=this.expression.evaluation(symTable);
            TypeInterface typeId= (symTable.lookup(this.id)).get_type();
            if ((value.get_type()).equals(typeId))
                symTable.update(this.id,value);
            else
                throw new MyException("!ERROR! Declared variable type and expression does not match!");
        }
        else throw new MyException("!ERROR! Variable not declared before!");
        return state;
    }

    public String toString()
    {
        return this.id + " = " + this.expression.toString();
    }
}
