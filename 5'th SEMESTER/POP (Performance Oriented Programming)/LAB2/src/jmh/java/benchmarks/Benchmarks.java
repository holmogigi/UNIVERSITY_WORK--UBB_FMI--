package benchmarks;

import org.example.entity.Order;
import org.example.repository.impl.eclipse_collections.MutableListRepository;
import org.example.repository.impl.fast_util.IntArrayListRepository;
import org.example.repository.impl.fast_util.IntIntHashMapRepository;
import org.example.repository.impl.fast_util.LongOpenHashSetRepository;
import org.example.repository.impl.jdk.ArrayListRepository;
import org.example.repository.impl.jdk.ConcurrentHashMapRepository;
import org.example.repository.impl.jdk.HashSetRepository;
import org.example.repository.impl.jdk.TreeSetRepository;
import org.openjdk.jmh.annotations.*;
import org.openjdk.jmh.runner.Runner;
import org.openjdk.jmh.runner.RunnerException;
import org.openjdk.jmh.runner.options.Options;
import org.openjdk.jmh.runner.options.OptionsBuilder;

import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import java.util.concurrent.TimeUnit;

public class Benchmarks {
    public static List<Order> getMockOrderList() {
        return Arrays.asList(
                new Order(1, 30, 5),
                new Order(2, 40, 10),
                new Order(3, 50, 2),
                new Order(4, 255, 7),
                new Order(5, 355, 11)
        );
    }

    public static Order getExistingMockOrder() {
        return new Order(4, 255, 7);
    }

    public static List<Integer> getMockIntegerList() {
        return Arrays.asList(122, 3, 45, 22, 44, 2);
    }

    public static Integer getExistingInteger() {
        return 22;
    }

    public static List<Long> getMockLongList() {
        return Arrays.asList(122L, 3L, 45L, 22L, 44L, 2L);
    }

    public static Long getExistingLong() {
        return 22L;
    }


    @State(Scope.Benchmark)
    public static class ArrayListRepositoryEP {
        public ArrayListRepository<Order> arrayListRepository = new ArrayListRepository<>();

        public Collection<Order> collection;

        public Order existingOrder;

        @Setup(Level.Invocation)
        public void setup() {
            arrayListRepository.clear();
            collection = Benchmarks.getMockOrderList();
            existingOrder = Benchmarks.getExistingMockOrder();
        }
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void arrayListAdd(ArrayListRepositoryEP executionPlan) {
        executionPlan.arrayListRepository.addAll(executionPlan.collection);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void arrayListContains(ArrayListRepositoryEP executionPlan) {
        Order order = executionPlan.existingOrder;
        executionPlan.arrayListRepository.contains(order);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void arrayListRemove(ArrayListRepositoryEP executionPlan) {
        Order order = executionPlan.existingOrder;
        executionPlan.arrayListRepository.remove(order);
    }

    @State(Scope.Benchmark)
    public static class ConcurrentHashMapRepositoryEP {
        public ConcurrentHashMapRepository<Order> concurrentHashMapRepository = new ConcurrentHashMapRepository<>();

        public Collection<Order> collection;

        public Order existingOrder;

        @Setup(Level.Invocation)
        public void setup() {
            concurrentHashMapRepository.clear();
            collection = Benchmarks.getMockOrderList();
            existingOrder = Benchmarks.getExistingMockOrder();
        }
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void concurrentHashMapAdd(ConcurrentHashMapRepositoryEP executionPlan) {
        executionPlan.concurrentHashMapRepository.addAll(executionPlan.collection);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void concurrentHashMapContains(ConcurrentHashMapRepositoryEP executionPlan) {
        Order order = executionPlan.existingOrder;
        executionPlan.concurrentHashMapRepository.contains(order);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void concurrentHashMapRemove(ConcurrentHashMapRepositoryEP executionPlan) {
        Order order = executionPlan.existingOrder;
        executionPlan.concurrentHashMapRepository.remove(order);
    }


    @State(Scope.Benchmark)
    public static class HashSetRepositoryEP {
        public HashSetRepository<Order> hashSetRepository = new HashSetRepository<>();

        public Collection<Order> collection;

        public Order existingOrder;

        @Setup(Level.Invocation)
        public void setup() {
            this.hashSetRepository.clear();
            collection = Benchmarks.getMockOrderList();
            existingOrder = Benchmarks.getExistingMockOrder();
        }
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void hashSetAdd(HashSetRepositoryEP executionPlan) {
        executionPlan.hashSetRepository.addAll(executionPlan.collection);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void hashSetContains(HashSetRepositoryEP executionPlan) {
        Order order = executionPlan.existingOrder;
        executionPlan.hashSetRepository.contains(order);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void hashSetRemove(HashSetRepositoryEP executionPlan) {
        Order order = executionPlan.existingOrder;
        executionPlan.hashSetRepository.remove(order);
    }


    @State(Scope.Benchmark)
    public static class TreeSetRepositoryEP {
        public TreeSetRepository<Order> treeSetRepository = new TreeSetRepository<>();

        public Collection<Order> collection;

        public Order existingOrder;

        @Setup(Level.Invocation)
        public void setup() {
            treeSetRepository.clear();
            collection = Benchmarks.getMockOrderList();
            existingOrder = Benchmarks.getExistingMockOrder();
        }
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void treeSetAdd(TreeSetRepositoryEP executionPlan) {
        executionPlan.treeSetRepository.addAll(executionPlan.collection);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void treeSetContains(TreeSetRepositoryEP executionPlan) {
        Order order = executionPlan.existingOrder;
        executionPlan.treeSetRepository.contains(order);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void treeSetRemove(TreeSetRepositoryEP executionPlan) {
        Order order = executionPlan.existingOrder;
        executionPlan.treeSetRepository.remove(order);
    }


    @State(Scope.Benchmark)
    public static class IntArrayListRepositoryEP {
        public IntArrayListRepository intArrayListRepository = new IntArrayListRepository();

        public Collection<Integer> collection;

        public Integer existingInteger;

        @Setup(Level.Invocation)
        public void setUp(){
            intArrayListRepository.clear();
            collection = Benchmarks.getMockIntegerList();
            existingInteger = Benchmarks.getExistingInteger();
        }
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void intArrayListAdd(IntArrayListRepositoryEP executionPlan) {
        executionPlan.intArrayListRepository.addAll(executionPlan.collection);

    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void intArrayListContains(IntArrayListRepositoryEP executionPlan) {
        Integer integer = executionPlan.existingInteger;
        executionPlan.intArrayListRepository.contains(integer);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void intArrayListRemove(IntArrayListRepositoryEP executionPlan) {
        Integer integer = executionPlan.existingInteger;
        executionPlan.intArrayListRepository.remove(integer);
    }


    @State(Scope.Benchmark)
    public static class IntIntHashMapRepositoryEP {
        public IntIntHashMapRepository intIntHashMapRepository = new IntIntHashMapRepository();

        public Collection<Integer> collection;

        public Integer existingInteger;

        @Setup(Level.Invocation)
        public void setUp(){
            intIntHashMapRepository.clear();
            collection = Benchmarks.getMockIntegerList();
            existingInteger = Benchmarks.getExistingInteger();
        }
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void intIntHashMapAdd(IntIntHashMapRepositoryEP executionPlan) {
        executionPlan.intIntHashMapRepository.addAll(executionPlan.collection);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void intIntHashMapContains(IntIntHashMapRepositoryEP executionPlan) {
        Integer integer = executionPlan.existingInteger;
        executionPlan.intIntHashMapRepository.contains(integer);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void intIntHashMapRemove(IntIntHashMapRepositoryEP executionPlan) {
        Integer integer = executionPlan.existingInteger;
        executionPlan.intIntHashMapRepository.remove(integer);
    }

    @State(Scope.Benchmark)
    public static class LongOpenHashSetRepositoryEP {
        public LongOpenHashSetRepository longOpenHashSetRepository = new LongOpenHashSetRepository();

        public Collection<Long> collection;

        public Long existingLong;

        @Setup(Level.Invocation)
        public void setUp(){
            longOpenHashSetRepository.clear();
            collection = Benchmarks.getMockLongList();
            existingLong = Benchmarks.getExistingLong();
        }
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void longOpenHashSetAdd(LongOpenHashSetRepositoryEP executionPlan) {
        executionPlan.longOpenHashSetRepository.addAll(executionPlan.collection);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void longOpenHashSetContains(LongOpenHashSetRepositoryEP executionPlan) {
        Long longValue = executionPlan.existingLong;
        executionPlan.longOpenHashSetRepository.contains(longValue);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void longOpenHashSetRemove(LongOpenHashSetRepositoryEP executionPlan) {
        Long longValue = executionPlan.existingLong;
        executionPlan.longOpenHashSetRepository.remove(longValue);
    }

    @State(Scope.Benchmark)
    public static class MutableListRepositoryEP {
        public MutableListRepository<Order> mutableListRepository = new MutableListRepository<>();

        public Collection<Order> collection;

        public Order existingOrder;

        @Setup(Level.Invocation)
        public void setUp(){
            mutableListRepository.clear();
            collection = Benchmarks.getMockOrderList();
            existingOrder = Benchmarks.getExistingMockOrder();
        }
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void mutableListAdd(MutableListRepositoryEP executionPlan) {
        executionPlan.mutableListRepository.addAll(executionPlan.collection);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void mutableListContains(MutableListRepositoryEP executionPlan) {
        executionPlan.mutableListRepository.contains(executionPlan.existingOrder);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void mutableListRemove(MutableListRepositoryEP executionPlan) {
        executionPlan.mutableListRepository.remove(executionPlan.existingOrder);
    }

    public static void main(String[] args) throws RunnerException {
        Options opt = new OptionsBuilder()
                .include(Benchmarks.class.getSimpleName())
                .forks(1)
                .measurementIterations(5)  // Adjust this value
                .warmupIterations(3)       // Adjust this value
                .build();
        new Runner(opt).run();
    }
}