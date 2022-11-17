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
import java.io.FileReader;
import java.io.IOException;
import java.lang.reflect.Type;

public class OpenFileStatement implements  StatementInterface
{

    private ExpressionInterface exp;

    public OpenFileStatement(ExpressionInterface e)
    {
        this.exp=e;
    }

    @Override
    public ProgramState exe(ProgramState state) throws MyException
    {
        AdtDictionaryInterface<String, BufferedReader> fileTable = state.getFileTable();
        ValueInterface value=this.exp.evaluation(state.get_symTable());
        TypeInterface value_type=value.get_type();

        if (value_type.equals(new StringType()))
        {
            StringValue string_value= (StringValue) value;
            if (!fileTable.isDefined(string_value.getValue()))
            {
                try {
                    BufferedReader file = new BufferedReader(new FileReader(string_value.getValue()));
                    fileTable.put(string_value.getValue(), file);
                } catch (IOException e) {
                    throw new MyException(e.getMessage());
                }
            }
                else
                {
                    throw new MyException("!ERROR! File already opened!");
                }
        }
        else
        {
            throw new MyException("!ERROR! Invalid type!");
        }
        return state;
    }

    public String toString()
    {
        return "OpenRFile(" + this.exp.toString() + ")";
    }
}
