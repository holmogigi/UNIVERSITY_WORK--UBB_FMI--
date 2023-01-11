package Model.Value;

import Model.Type.StringType;
import Model.Type.TypeInterface;

public class StringValue implements  ValueInterface
{
    private String value;

    public StringValue()
    {
        this.value="";
    }

    public StringValue(String val)
    {
        this.value=val;
    }

    public String getValue()
    {
        return value;
    }

    @Override
    public TypeInterface get_type()
    {
        return new StringType();
    }

    @Override
    public boolean equals(Object another)
    {
        StringValue str=(StringValue) another;
        return this.value.equals(str);
    }

    @Override
    public ValueInterface deepCopy()
    {
        return new StringValue(value);
    }

    public String toString()
    {
        return this.value;
    }
}
