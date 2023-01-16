package Model.ADT;
import Exceptions.MyException;

import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class AdtDictionary<K, V> implements AdtDictionaryInterface<K, V>
{
    private Map<K, V> dictionary;

    public AdtDictionary()
    {
        dictionary=new HashMap<K,V>();
    }

    @Override
    public boolean isDefined(K key) {
        return dictionary.containsKey(key);
    }

    @Override
    public V lookup(K key) throws MyException
    {
        V value = this.dictionary.get(key);
        if (value == null)
            throw new MyException("!ERROR! Variable not defined!");
        else
            return value;
    }

    @Override
    public void update(K key, V value)
    {
        this.dictionary.replace(key, value);
    }

    @Override
    public void put(K key, V value)
    {
        this.dictionary.put(key, value);
    }

    @Override
    public boolean isEmpty()
    {
        return this.dictionary.isEmpty();
    }

    public String toString()
    {
        String s = "";
        Iterator it = this.dictionary.keySet().iterator();
        while(it.hasNext())
        {
            K key = (K)it.next();
            s += key.toString() + "=";
            V value = this.dictionary.get(key);
            s += value.toString() + "\n";
        }
        return s;
    }

    @Override
    public Collection<V> values()
    {
        return this.dictionary.values();
    }

    @Override
    public void delete(K key)
    {
        this.dictionary.remove(key);
    }

    @Override
    public Map<K,V> getContent() {
        return this.dictionary;
    }

    @Override
    public AdtDictionaryInterface<K, V> deepCopy() throws MyException {
        AdtDictionaryInterface<K, V> toReturn= new AdtDictionary<>();
        for (K key: dictionary.keySet())
            toReturn.put(key,lookup(key));
        return toReturn;
    }

}
