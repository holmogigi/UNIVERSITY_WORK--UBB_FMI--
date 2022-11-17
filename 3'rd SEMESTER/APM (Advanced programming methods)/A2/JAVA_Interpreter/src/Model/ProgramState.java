package Model;
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

    public AdtDictionaryInterface<String, BufferedReader> getFileTable()
    {
        return this.fileTable;
    }

    public ProgramState(AdtStackInterface<StatementInterface> stack, AdtDictionaryInterface<String, ValueInterface> dictionary, AdtListInterface<ValueInterface> list, StatementInterface program, AdtDictionaryInterface <String,BufferedReader> fileTable)
    {
        this.exeStack=stack;
        this.symTable=dictionary;
        this.out=list;
        this.fileTable=fileTable;
        stack.push(program);
    }

    public String toString()
    {
        String s="";
        s+="exeStack: ";
        s+=this.exeStack.toString();
        s+="\nsymTable: ";
        s+=this.symTable.toString();
        s+="Out:";
        s+=this.out.toString()+"\n";
        s+="FileTable:";
        s+=this.fileTable.toString()+"\n";
        return s;
    }

}
