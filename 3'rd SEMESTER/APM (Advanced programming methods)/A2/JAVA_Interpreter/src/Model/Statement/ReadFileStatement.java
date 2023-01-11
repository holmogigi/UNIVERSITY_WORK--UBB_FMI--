package Model.Statement;
import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.Expression.ExpressionInterface;
import Model.ProgramState;
import Model.Type.IntType;
import Model.Type.StringType;
import Model.Type.TypeInterface;
import Model.Value.IntValue;
import Model.Value.StringValue;
import Model.Value.ValueInterface;

import java.io.BufferedReader;
import java.io.IOException;

public class ReadFileStatement implements StatementInterface
{
    private ExpressionInterface exp;
    private String name;

    public ReadFileStatement(ExpressionInterface e, String n)
    {
        this.exp=e;
        this.name=n;
    }

    @Override
    public AdtDictionaryInterface<String, TypeInterface> typeCheck(AdtDictionaryInterface<String, TypeInterface> typeEnv) throws Exception {
        if (this.exp.typeCheck(typeEnv).equals(new StringType()))
            return typeEnv;
        else
            throw new MyException("!ERROR! Non string expression in Read!");
    }

    @Override
    public ProgramState exe(ProgramState state) throws MyException
    {
        AdtDictionaryInterface<String, ValueInterface> symTable = state.get_symTable();
       AdtDictionaryInterface<String, BufferedReader> fileTable = state.getFileTable();

        if (symTable.isDefined(this.name)) {
            ValueInterface value = symTable.lookup(this.name);
            if (value.get_type().equals(new IntType())) {
                value = this.exp.evaluation(symTable, state.getHeap());
                if (value.get_type().equals(new StringType())) {
                    StringValue castValue = (StringValue) value;
                    if (fileTable.isDefined(castValue.getValue())) {
                        BufferedReader br = fileTable.lookup(castValue.getValue());
                        try {
                            String line = br.readLine();
                            if (line == null)
                                line = "0";
                            symTable.put(this.name, new IntValue(Integer.parseInt(line)));
                        } catch (IOException e) {
                            throw new MyException("!ERROR! Unable to read from file!");
                        }
                    } else {
                        throw new MyException("!ERROR! FileTable does not contain string!");
                    }
                } else {
                    throw new MyException("!ERROR! Not stringType!");
                }
            } else {
                throw new MyException("!ERROR! Not intType!");
            }
        } else {
            throw new MyException("!ERROR! String not in SymTable!");
        }
        return state;
    }

    @Override
    public StatementInterface deepCopy()
    {
        return new ReadFileStatement(exp.deepCopy(), name);
    }

    public String toString()
    {
        return "readRFile(" + this.exp.toString() + ", " + this.name + ")";
    }
}
