package Model.ADT;

import Exceptions.MyException;

public interface AdtStackInterface<T>
{
    public T pop() throws MyException;
    public void push(T v);
    public boolean isEmpty();

}
