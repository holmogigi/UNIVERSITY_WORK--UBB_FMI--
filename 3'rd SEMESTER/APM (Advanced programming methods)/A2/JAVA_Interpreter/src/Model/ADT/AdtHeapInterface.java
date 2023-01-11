package Model.ADT;
import Exceptions.MyException;
import Model.Value.ValueInterface;
import java.util.HashMap;
import java.util.Set;

public interface AdtHeapInterface
{
    int getFreeValue();
    HashMap<Integer, ValueInterface> getContent();
    void setContent(HashMap<Integer, ValueInterface> newMap);
    int add(ValueInterface value);
    void update(Integer position, ValueInterface value) throws MyException;
    ValueInterface get(Integer position) throws MyException;
    boolean containsKey(Integer position);
    void remove(Integer key) throws MyException;
    Set<Integer> keySet();


}
