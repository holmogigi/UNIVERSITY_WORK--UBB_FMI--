package Model.Type;
import Model.Value.StringValue;
import Model.Value.ValueInterface;

public class StringType implements TypeInterface{

    @Override
    public boolean equals(TypeInterface type)
    {
       return type instanceof StringType;
    }

    @Override
    public ValueInterface defaultValue()
    {
        return new StringValue();
    }

    @Override
    public TypeInterface deepCopy()
    {
        return new StringType();
    }

    public String toString()
    {
        return "string";
    }
}
