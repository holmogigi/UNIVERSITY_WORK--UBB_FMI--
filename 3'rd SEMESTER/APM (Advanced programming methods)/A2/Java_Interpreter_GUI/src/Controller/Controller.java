package Controller;
import Exceptions.MyException;
import Model.ProgramState.ProgramState;
import Model.Value.RefValue;
import Model.Value.ValueInterface;
import Repository.RepositoryInterface;

import java.io.IOException;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Controller
{
    private RepositoryInterface repo;
    private ExecutorService executorService;

    public Controller(RepositoryInterface rep)
    {
        this.repo=rep;
    }

    public List<Integer> getAddrFromHeap(Collection<ValueInterface> heapValues) {
        return heapValues.stream()
                .filter(v -> v instanceof RefValue)
                .map(v -> {RefValue v1 = (RefValue) v; return v1.getAddress();})
                .collect(Collectors.toList());
    }

    public List<Integer> getAddrFromSymTable(Collection<ValueInterface> symTableValues) {
        return symTableValues.stream()
                .filter(v -> v instanceof RefValue)
                .map(v -> {RefValue v1 = (RefValue) v; return v1.getAddress();})
                .collect(Collectors.toList());
    }

    public Map<Integer, ValueInterface> safeGarbageCollector(List<Integer> symTableAddr, List<Integer> heapAddr, Map<Integer, ValueInterface> heap) {
        return heap.entrySet().stream()
                .filter(e -> ( symTableAddr.contains(e.getKey()) || heapAddr.contains(e.getKey())))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue, (e1, e2) -> e1, HashMap::new));
    }

    public void conservativeGarbageCollector(List<ProgramState> programStates) {
        List<Integer> symTableAddresses = Objects.requireNonNull(programStates.stream()
                        .map(p -> getAddrFromSymTable(p.get_symTable().values()))
                        .map(Collection::stream)
                        .reduce(Stream::concat).orElse(null))
                .collect(Collectors.toList());
        programStates.forEach(p -> {
            p.getHeap().setContent((HashMap<Integer,ValueInterface>) safeGarbageCollector(symTableAddresses, getAddrFromHeap(p.getHeap().getContent().values()), p.getHeap().getContent()));
        });
    }

    public void oneStepForAllPrograms(List<ProgramState> programStates) throws InterruptedException, IOException, MyException{
        programStates.forEach(programState -> {
                    try {
                        repo.logProgState(programState);
                        System.out.println(programState.toString());
                    } catch (MyException e) {
                        throw new RuntimeException(e);
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
        });
        List<Callable<ProgramState>> callList = programStates.stream()
                .map((ProgramState p) -> (Callable<ProgramState>) (p::singleStep))
                .collect(Collectors.toList());

        List<ProgramState> newProgramList = executorService.invokeAll(callList).stream()
                .map(future -> {
                    try {
                        return future.get();
                    } catch (InterruptedException | ExecutionException e) {
                        System.out.println("\u001B[31m" + e.getMessage() + "\u001B[0m");
                    }
                    return null;
                })
                .filter(Objects::nonNull)
                .collect(Collectors.toList());

        programStates.addAll(newProgramList);

        programStates.forEach(programState -> {
            try {
                repo.logProgState(programState);
                System.out.println(programState.toString());
            } catch (IOException | MyException e) {
                System.out.println("\u001B[31m" + e.getMessage() + "\u001B[0m");
            }
        });
        repo.setProgramList(programStates);
    }

    public List<ProgramState> removeDuplicateStates(List<ProgramState> prgList)
    {
        return prgList.stream().distinct().collect(Collectors.toList());
    }

    public void all_steps() throws MyException, IOException, InterruptedException {
        executorService = Executors.newFixedThreadPool(2);
        List<ProgramState> program= removeCompletedProgram(repo.getProgramList());
        while (program.size() > 0)
        {
            conservativeGarbageCollector(program);
            oneStepForAllPrograms(program);
            program=removeCompletedProgram(repo.getProgramList());
            program=removeDuplicateStates(program);
        }
        executorService.shutdownNow();
        repo.setProgramList(program);
    }

    public void oneStep() throws InterruptedException, MyException, IOException {
        executorService = Executors.newFixedThreadPool(2);
        List<ProgramState> programStates = removeCompletedProgram(repo.getProgramList());
        oneStepForAllPrograms(programStates);
        conservativeGarbageCollector(programStates);
        //programStates = removeCompletedPrg(repository.getProgramList());
        executorService.shutdownNow();
        //repository.setProgramStates(programStates);
    }

    public void setProgramStates(List<ProgramState> programStates) {
        this.repo.setProgramList(programStates);
    }

    public List<ProgramState> removeCompletedProgram(List<ProgramState> prgList)
    {
        return prgList.stream().filter(p -> !p.isNotCompleted()).collect(Collectors.toList());
    }

    public List<ProgramState> getProgramStates() {
        return this.repo.getProgramList();
    }
}
