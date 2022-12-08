package Model.ADT;
import Exceptions.MyException;
import Model.Value.ValueInterface;

import java.util.Collection;
import java.util.HashMap;
import java.util.Set;

public class AdtHeap implements AdtHeapInterface
{
    HashMap<Integer, ValueInterface> heap;
    Integer freeLocation;

    public int newValue()
    {
        this.freeLocation+=1;
        while (this.heap.containsKey(freeLocation))
            this.freeLocation+=1;
        return freeLocation;
    }

    public AdtHeap()
    {
        this.heap=new HashMap<>();
        this.freeLocation=1;
    }

    @Override
    public int getFreeValue()
    {
        return this.freeLocation;
    }

    @Override
    public HashMap<Integer, ValueInterface> getContent()
    {
        return this.heap;
    }

    @Override
    public void setContent(HashMap<Integer, ValueInterface> newMap)
    {
        this.heap=newMap;
    }

    @Override
    public int add(ValueInterface value)
    {
        this.heap.put(this.freeLocation, value);
        Integer loc=this.freeLocation;
        this.freeLocation=newValue();
        return loc;
    }

    @Override
    public void update(Integer position, ValueInterface value) throws MyException
    {
        if (!this.heap.containsKey(position))
            throw new MyException("!ERROR! Value is not in the heap!");
        this.heap.put(position,value);
    }

    @Override
    public ValueInterface get(Integer position) throws MyException
    {
        if (!this.heap.containsKey(position))
            throw new MyException("!ERROR! Value is not in the heap!");
        return this.heap.get(position);
    }

    @Override
    public boolean containsKey(Integer position)
    {
        return this.heap.containsKey(position);
    }

    @Override
    public void remove(Integer key) throws MyException
    {
        if (!containsKey(key))
            throw new MyException("!ERROR! Key not defined!");
        this.freeLocation=key;
        this.heap.remove(key);
    }

    @Override
    public Set<Integer> keySet()
    {
        return this.heap.keySet();
    }


    public String toString()
    {
        return this.heap.toString();
    }
}

