package Model.Value;
import Model.Type.RefType;
import Model.Type.TypeInterface;

public class RefValue implements ValueInterface
{
    int address;
    TypeInterface locationType;

    public RefValue(int address, TypeInterface locationType)
    {
        this.address=address;
        this.locationType=locationType;
    }

    public int getAddress()
    {
        return this.address;
    }

    public TypeInterface getLocationType()
    {
        return this.locationType;
    }

    @Override
    public TypeInterface get_type()
    {
        return new RefType(locationType);
    }

    @Override
    public ValueInterface deepCopy()
    {
        return new RefValue(address, locationType.deepCopy());
    }

    public String toString()
    {
        return String.format("(%d, %s)", this.address, this.locationType);
    }
}
