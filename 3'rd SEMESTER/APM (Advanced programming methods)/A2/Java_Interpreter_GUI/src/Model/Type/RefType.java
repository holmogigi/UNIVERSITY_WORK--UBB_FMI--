package Model.Type;
import Model.Value.RefValue;
import Model.Value.ValueInterface;

public class RefType implements TypeInterface
{
    TypeInterface inner;

    public RefType(TypeInterface inner)
    {
        this.inner=inner;
    }

    public TypeInterface getInner()
    {
        return this.inner;
    }

    @Override
    public boolean equals(TypeInterface type)
    {
        if (type instanceof RefType)
            return inner.equals(((RefType) type).getInner());
        else
            return false;
    }

    @Override
    public ValueInterface defaultValue()
    {
        return new RefValue(0, this.inner);
    }

    @Override
    public TypeInterface deepCopy()
    {
        return new RefType(inner.deepCopy());
    }

    public String toString()
    {
        return String.format("Ref(%s) ", this.inner);
    }
}
