package Model.ADT;
import Exceptions.MyException;
import View.Command;

import java.util.Collection;
import java.util.Map;

public interface AdtDictionaryInterface<K, V>
{
    public boolean isDefined(K key);
    public V lookup (K key) throws MyException;
    public void update(K key, V value);
    public void put(K key, V value);
    public boolean isEmpty();
    public Collection<V> values();
    public void delete(K key);
    public Map<K,V> getContent();
    public AdtDictionaryInterface<K, V> deepCopy() throws MyException;
}
