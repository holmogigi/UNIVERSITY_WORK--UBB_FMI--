package Model.Value;
import Model.Type.BoolType;
import Model.Type.TypeInterface;

public class BoolValue implements ValueInterface
{
    private boolean value;

    public BoolValue()
    {
        this.value=false;
    }

    public BoolValue(boolean bool)
    {
        this.value=bool;
    }

    public boolean get_value()
    {
        return this.value;
    }

    @Override
    public TypeInterface get_type()
    {
        return new BoolType();
    }

    public String toString()
    {
        return String.valueOf(this.value);
    }

    @Override
    public ValueInterface deepCopy()
    {
        return new BoolValue(value);
    }

    public boolean equals(Object another)
    {
        BoolValue value1=(BoolValue) another;
        return this.value==value1.get_value();
    }
}
