package Model.Statement;
import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.ProgramState;
import Model.Type.BoolType;
import Model.Type.IntType;
import Model.Type.StringType;
import Model.Type.TypeInterface;
import Model.Value.BoolValue;
import Model.Value.IntValue;
import Model.Value.StringValue;
import Model.Value.ValueInterface;

public class VariableDeclarationStatement implements StatementInterface
{
    private String var_name;
    private TypeInterface var_type;

    public VariableDeclarationStatement(String name, TypeInterface type)
    {
        this.var_name=name;
        this.var_type=type;
    }

    @Override
    public AdtDictionaryInterface<String, TypeInterface> typeCheck(AdtDictionaryInterface<String, TypeInterface> typeEnv) throws Exception {
        typeEnv.put(var_name,var_type);
        return typeEnv;
    }

    @Override
    public ProgramState exe(ProgramState state) throws MyException
    {
        AdtDictionaryInterface<String, ValueInterface> sym_table=state.get_symTable();
        if (sym_table.isDefined(var_name))
            throw new MyException("!ERROR! Variable already defined!");
        else
        {
            if (this.var_type.equals(new IntType()))
            {
                ValueInterface value=new IntValue();
                sym_table.put(this.var_name,value);
            }
            else if (this.var_type.equals(new BoolType()))
            {
                ValueInterface value=new BoolValue();
                sym_table.put(this.var_name, value);
            }
            else if (this.var_type.equals(new StringType()))
            {
                ValueInterface value=new StringValue();
                sym_table.put(this.var_name,value);
            }
            else
            {
                ValueInterface value= var_type.defaultValue();
                sym_table.put(this.var_name,value);
            }
        }
        return state;
    }

    @Override
    public StatementInterface deepCopy()
    {
        return new VariableDeclarationStatement(var_name, var_type.deepCopy());
    }

    public String toString()
    {
        return this.var_type + " " +this.var_name;
    }
}
