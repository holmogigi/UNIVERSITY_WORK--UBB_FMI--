package Controller;
import Exceptions.MyException;
import Model.ADT.AdtStackInterface;
import Model.ProgramState;
import Model.Statement.StatementInterface;
import Model.Value.RefValue;
import Model.Value.ValueInterface;
import Repository.RepositoryInterface;

import java.io.IOException;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Controller
{
    private RepositoryInterface repo;

    public Controller(RepositoryInterface rep)
    {
        this.repo=rep;
    }

    HashMap<Integer, ValueInterface> unsafeGarbageCollector(List<Integer> symTableAddr, HashMap<Integer, ValueInterface> heap) {
        return heap.entrySet().stream()
                .filter(e->symTableAddr.contains(e.getKey()))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue, (e1, e2) -> e1, HashMap::new));
    }

    List<Integer> getAddrFromSymTable(Collection<ValueInterface> symTableValues, Collection<ValueInterface> heapValues) {
        return Stream.concat(
                heapValues.stream()
                        .filter(v->v instanceof RefValue)
                        .map(v-> {RefValue v1 = (RefValue)v; return v1.getAddress();}),
                symTableValues.stream()
                        .filter(v->v instanceof RefValue)
                        .map(v-> {RefValue v1 = (RefValue)v; return v1.getAddress();})
        ).collect(Collectors.toList());
    }

    public ProgramState single_step(ProgramState state) throws MyException
    {
        AdtStackInterface<StatementInterface> stackexe= state.get_exeStack();
        if (stackexe.isEmpty())
            throw new MyException("!ERROR! Program exe stack empty!");
        StatementInterface curr_statement=stackexe.pop();
        return curr_statement.exe(state);
    }

    public void all_steps() throws MyException, IOException {
        ProgramState program = this.repo.get_prgState();
        this.repo.logProgState();
        try {
            while (!program.get_exeStack().isEmpty()) {
                single_step(program);
                System.out.println(program.toString());
                this.repo.logProgState();
                program.getHeap().setContent(unsafeGarbageCollector(getAddrFromSymTable(program.get_symTable().getContent().values(), program.getHeap().getContent().values()), program.getHeap().getContent()));
                this.repo.logProgState();
            }
        } catch (MyException e) {
            System.out.println(e.getMessage());
        }
    }
}
