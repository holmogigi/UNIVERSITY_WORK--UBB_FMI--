package Model.ADT;
import java.util.Stack;

public class AdtStack<T> implements AdtStackInterface<T>
{
    private Stack<T> stack;

    public AdtStack()
    {
        this.stack=new Stack<T>();
    }

    @Override
    public T pop()
    {
       return this.stack.pop();
    }

    @Override
    public void push(T v)
    {
        this.stack.push(v);
    }

    @Override
    public boolean isEmpty()
    {
        return this.stack.isEmpty();
    }

    public String toString()
    {

        String s = "";
        Stack<T> stk2 = (Stack<T>) this.stack.clone();
        while (!stk2.isEmpty()) {
            T val = stk2.pop();
            s += val.toString();
        }
        return s;


    }
}
