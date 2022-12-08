package Model.Type;

import Model.Value.IntValue;
import Model.Value.ValueInterface;

public class IntType implements TypeInterface
{
    @Override
    public boolean equals(TypeInterface type)
    {
        return type instanceof IntType;
    }

    @Override
    public ValueInterface defaultValue() {
        return new IntValue();
    }

    public String toString()
    {
        return "int";
    }
}
