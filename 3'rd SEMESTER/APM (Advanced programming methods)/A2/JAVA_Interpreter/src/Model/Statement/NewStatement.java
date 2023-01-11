package Model.Statement;
import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.ADT.AdtHeapInterface;
import Model.Expression.ExpressionInterface;
import Model.ProgramState;
import Model.Type.RefType;
import Model.Type.TypeInterface;
import Model.Value.RefValue;
import Model.Value.ValueInterface;

public class NewStatement implements StatementInterface
{
    private String varName;
    private ExpressionInterface exp;

    public NewStatement(String var, ExpressionInterface inter)
    {
        this.varName=var;
        this.exp=inter;
    }

    @Override
    public AdtDictionaryInterface<String, TypeInterface> typeCheck(AdtDictionaryInterface<String, TypeInterface> typeEnv) throws Exception {
        TypeInterface typeVar=typeEnv.lookup(this.varName);
        TypeInterface typeExpr= this.exp.typeCheck(typeEnv);
        if (typeVar.equals(new RefType(typeExpr)))
            return typeEnv;
        else
            throw new MyException("!ERROR! Different types in newStatement!");
    }

    @Override
    public ProgramState exe(ProgramState state) throws MyException
    {
        AdtDictionaryInterface<String, ValueInterface> symTable = state.get_symTable();
        AdtHeapInterface heap = state.getHeap();
        if (!symTable.isDefined(this.varName))
            throw new MyException("!ERROR! Value not in symTable!");
        ValueInterface varValue = symTable.lookup(this.varName);
        if (!(varValue.get_type() instanceof RefType))
            throw new MyException("!ERROR! Value is not of RefType!");
        ValueInterface evaluated = this.exp.evaluation(symTable, heap);
        TypeInterface locationType = ((RefValue)varValue).getLocationType();
        if (!locationType.equals(evaluated.get_type()))
            throw new MyException("!ERROR! Variable has wrong type!");
        int newPosition = heap.add(evaluated);
        symTable.put(varName, new RefValue(newPosition, locationType));
        state.set_symTable(symTable);
        state.setHeap(heap);
        return state;
    }

    @Override
    public StatementInterface deepCopy()
    {
        return new NewStatement(varName, exp.deepCopy());
    }

    public String toString()
    {
        return String.format("New(%s, %s)", this.varName, this.exp);
    }
}
