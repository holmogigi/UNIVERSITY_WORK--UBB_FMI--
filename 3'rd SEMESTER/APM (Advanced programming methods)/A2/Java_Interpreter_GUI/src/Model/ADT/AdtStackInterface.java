package Model.ADT;

import Exceptions.MyException;

import java.util.List;

public interface AdtStackInterface<T>
{
    public T pop() throws MyException;
    public void push(T v);
    public boolean isEmpty();
    public List<T> getReversed();
}
