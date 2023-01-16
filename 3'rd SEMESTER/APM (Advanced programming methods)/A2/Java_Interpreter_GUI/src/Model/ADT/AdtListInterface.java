package Model.ADT;

import java.util.List;

public interface AdtListInterface <T>
{
    public void add(T elem);
    public int size();
    public T get(int i);
    public List<T> getList();
}
