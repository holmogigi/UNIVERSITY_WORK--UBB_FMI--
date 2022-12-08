package Model.Statement;
import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.ADT.AdtHeap;
import Model.ADT.AdtHeapInterface;
import Model.Expression.ExpressionInterface;
import Model.ProgramState;
import Model.Value.RefValue;
import Model.Value.ValueInterface;

public class WriteHeapStatement implements StatementInterface
{
    String variableName;
    ExpressionInterface exp;

    public WriteHeapStatement(String variableName, ExpressionInterface expressionInterface)
    {
        this.variableName=variableName;
        this.exp=expressionInterface;
    }

    @Override
    public ProgramState exe(ProgramState state) throws MyException
    {
        AdtDictionaryInterface<String, ValueInterface> symTable = state.get_symTable();
        AdtHeapInterface heap = state.getHeap();
        if (!symTable.isDefined(this.variableName))
            throw new MyException("!ERROR! Value not in SymTable!");
        ValueInterface value = symTable.lookup(this.variableName);
        if (!(value instanceof RefValue))
            throw new MyException("!ERROR! Value not of RefType!");
        RefValue refValue = (RefValue) value;
        ValueInterface evaluated = this.exp.evaluation(symTable, heap);
        if (!evaluated.get_type().equals(refValue.getLocationType()))
            throw new MyException("!ERROR! Wrong statement!");
        heap.update(refValue.getAddress(), evaluated);
        state.setHeap(heap);
        return state;
    }

    public String toString()
    {
        return String.format("WriteHeap(%s, %s)", this.variableName, this.exp);
    }
}
