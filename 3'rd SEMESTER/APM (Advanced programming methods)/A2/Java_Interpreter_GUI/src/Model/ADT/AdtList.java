package Model.ADT;
import java.util.List;
import java.util.ArrayList;

public class AdtList<T> implements AdtListInterface<T>
{
    private List<T> list;

    public AdtList()
    {
        this.list=new ArrayList<T>();
    }

    @Override
    public void add(T elem)
    {
        this.list.add(elem);
    }

    @Override
    public int size()
    {
        return this.list.size();
    }

    @Override
    public T get(int i)
    {
        return this.list.get(i);
    }

    public String toString()
    {
        return this.list.toString();
    }

    @Override
    public List<T> getList() {
        synchronized (this) {
            return list;
        }
    }
}
