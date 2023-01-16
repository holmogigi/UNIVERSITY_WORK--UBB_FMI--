package Model.ProgramState;
import Exceptions.MyException;
import Model.ADT.AdtHeapInterface;
import Model.ADT.AdtStackInterface;
import Model.ADT.AdtListInterface;
import Model.ADT.AdtDictionaryInterface;
import Model.Statement.StatementInterface;
import Model.Value.ValueInterface;
import java.io.BufferedReader;

public class ProgramState
{
    private AdtStackInterface<StatementInterface> exeStack;
    private AdtDictionaryInterface<String, ValueInterface> symTable;
    private AdtListInterface<ValueInterface> out;
    private AdtDictionaryInterface<String, BufferedReader> fileTable;
    private AdtHeapInterface heap;
    private int id;
    private static int lastID=0;
    private StatementInterface originalProgram;

    public synchronized int setID()
    {
        this.lastID++;
        return this.lastID;
    }

    public int getId() {
        return this.id;
    }

    public AdtStackInterface<StatementInterface> get_exeStack()
    {
        return exeStack;
    }

    public void set_exeStack(AdtStackInterface<StatementInterface> stack)
    {
        this.exeStack=stack;
    }

    public AdtDictionaryInterface<String, ValueInterface> get_symTable()
    {
        return symTable;
    }

    public void set_symTable(AdtDictionaryInterface<String, ValueInterface> dictionary)
    {
        this.symTable=dictionary;
    }

    public AdtListInterface<ValueInterface> get_out()
    {
        return this.out;
    }

    public void set_out(AdtListInterface<ValueInterface> list)
    {
        this.out=list;
    }

    public AdtHeapInterface getHeap()
    {
        return this.heap;
    }

    public void setHeap(AdtHeapInterface newheap)
    {
        this.heap=newheap;
    }

    public AdtDictionaryInterface<String, BufferedReader> getFileTable()
    {
        return this.fileTable;
    }


    public ProgramState(AdtStackInterface<StatementInterface> stack, AdtDictionaryInterface<String,ValueInterface> symTable, AdtListInterface<ValueInterface> out, AdtDictionaryInterface<String, BufferedReader> fileTable, AdtHeapInterface heap, StatementInterface program) {
        this.exeStack = stack;
        this.symTable = symTable;
        this.out = out;
        this.fileTable = fileTable;
        this.heap = heap;
        this.originalProgram=program.deepCopy();
        this.exeStack.push(program);
        this.id = setID();
    }

    public ProgramState(AdtStackInterface<StatementInterface> stack, AdtDictionaryInterface<String,ValueInterface> symTable, AdtListInterface<ValueInterface> out, AdtDictionaryInterface<String, BufferedReader> fileTable, AdtHeapInterface heap) {
        this.exeStack = stack;
        this.symTable = symTable;
        this.out = out;
        this.fileTable = fileTable;
        this.heap = heap;
        this.id = setID();
    }

    public boolean isNotCompleted()
    {
        return this.exeStack.isEmpty();
    }

    public ProgramState singleStep() throws MyException {

        StatementInterface curStatement=exeStack.pop();
        return curStatement.exe(this);
    }

    public String toString()
    {
        String idd=Integer.toString(this.id);
        String s="";
        s+="\nId: ";
        s+=idd;
        s+="\nexeStack: ";
        s+=this.exeStack.toString();
        s+="\nsymTable: ";
        s+=this.symTable.toString();
        s+="Out:";
        s+=this.out.toString()+"\n";
        s+="FileTable:";
        s+=this.fileTable.toString()+"\n";
        s+="Heap: ";
        s+=this.heap.toString()+"\n";
        return s;
    }
}
