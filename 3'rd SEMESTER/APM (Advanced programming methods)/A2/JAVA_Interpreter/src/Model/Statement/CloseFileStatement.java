package Model.Statement;

import Exceptions.MyException;
import Model.ADT.AdtDictionaryInterface;
import Model.Expression.ExpressionInterface;
import Model.ProgramState;
import Model.Type.StringType;
import Model.Type.TypeInterface;
import Model.Value.StringValue;
import Model.Value.ValueInterface;

import java.io.BufferedReader;
import java.io.IOException;

public class CloseFileStatement implements StatementInterface
{
    private ExpressionInterface exp;

    public CloseFileStatement(ExpressionInterface e)
    {
        this.exp=e;
    }

    @Override
    public AdtDictionaryInterface<String, TypeInterface> typeCheck(AdtDictionaryInterface<String, TypeInterface> typeEnv) throws Exception
    {
        if (exp.typeCheck(typeEnv).equals(new StringType()))
            return typeEnv;
        else
            throw new Exception("!ERROR! No string expression!");
    }

    @Override
    public ProgramState exe(ProgramState state) throws MyException
    {
        AdtDictionaryInterface<String, ValueInterface> symTable = state.get_symTable();

        ValueInterface v = exp.evaluation(symTable, state.getHeap());
        TypeInterface t = v.get_type();
        if (!t.equals(new StringType()))
            throw new MyException("!ERROR! File name not string!");
        AdtDictionaryInterface<String, BufferedReader> fileTable = state.getFileTable();
        StringValue sv = (StringValue)v;
        if (!fileTable.isDefined(sv.getValue()))
            throw new MyException("!ERROR! File not opened yet!");
        BufferedReader reader = fileTable.lookup(sv.getValue());
        try{
            reader.close();
        }
        catch(IOException e) {
            throw new MyException("!ERROR! Unable to close file!");
        }
        fileTable.delete(sv.getValue());
        return state;
    }

    @Override
    public StatementInterface deepCopy()
    {
        return new CloseFileStatement(exp.deepCopy());
    }

    public String toString()
    {
        return "closeRFile(" + this.exp.toString() + ")";
    }
}
