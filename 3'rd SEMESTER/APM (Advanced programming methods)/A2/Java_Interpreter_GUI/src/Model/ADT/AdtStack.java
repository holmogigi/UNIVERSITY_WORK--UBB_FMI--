package Model.ADT;
import Exceptions.MyException;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Stack;

public class AdtStack<T> implements AdtStackInterface<T>
{
    private Stack<T> stack;

    public AdtStack()
    {
        this.stack=new Stack<>();
    }

    @Override
    public T pop() throws MyException {
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

    @Override
    public List<T> getReversed() {
        List<T> list = Arrays.asList((T[]) stack.toArray());
        Collections.reverse(list);
        return list;
    }

}
