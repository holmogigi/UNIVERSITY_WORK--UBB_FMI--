package Model.ADT;
import Exceptions.MyException;

import java.util.Collection;

public interface AdtDictionaryInterface<K, V>
{
    public boolean isDefined(K key);
    public V lookup (K key) throws MyException;
    public void update(K key, V value);
    public void put(K key, V value);
    public boolean isEmpty();
    public Collection<V> values();
    public void delete(K key);
}
