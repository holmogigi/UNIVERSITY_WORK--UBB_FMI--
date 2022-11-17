package Model.Type;

import Model.Value.BoolValue;
import Model.Value.ValueInterface;

public class BoolType implements TypeInterface
{
    @Override
    public boolean equals(TypeInterface type)
    {
        return type instanceof BoolType;
    }

    @Override
    public ValueInterface defaultValue()
    {
        return new BoolValue();
    }

    @Override
    public String toString()
    {
        return "bool";
    }
}
