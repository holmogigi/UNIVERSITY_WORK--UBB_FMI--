package Model.Value;
import Model.Type.IntType;
import Model.Type.TypeInterface;

public class IntValue implements ValueInterface
{
    private int value;

    public IntValue()
    {
        this.value=0;
    }

    public IntValue(int val)
    {
        this.value=val;
    }

    public int get_value()
    {
        return this.value;
    }

    @Override
    public TypeInterface get_type()
    {
        return new IntType();
    }

    public String toString()
    {
        return String.valueOf(this.value);
    }

    @Override
    public ValueInterface deepCopy()
    {
        return new IntValue(value);
    }

    public boolean equals(Object another)
    {
        IntValue value1=(IntValue) another;
        return this.value==value1.get_value();
    }
}
