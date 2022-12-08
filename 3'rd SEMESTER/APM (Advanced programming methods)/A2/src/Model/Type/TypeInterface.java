package Model.Type;

import Model.Value.ValueInterface;

public interface TypeInterface
{
    boolean equals(TypeInterface type);
    ValueInterface defaultValue();
}
