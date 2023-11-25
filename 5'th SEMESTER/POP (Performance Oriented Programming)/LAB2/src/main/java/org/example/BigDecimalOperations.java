/*
package org.example;

import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.*;
import java.util.stream.*;
import org.junit.jupiter.api.*;
import org.openjdk.jmh.annotations.*;

public class BigDecimalOperations {
    private List<BigDecimal> list;

    public BigDecimalOperations(List<BigDecimal> list) {
        this.list = list;
    }

    public BigDecimal sum() {
        return list.stream().reduce(BigDecimal.ZERO, BigDecimal::add);
    }

    public BigDecimal average() {
        return list.stream().reduce(BigDecimal.ZERO, BigDecimal::add).divide(BigDecimal.valueOf(list.size()), RoundingMode.HALF_UP);
    }

    public List<BigDecimal> topPercent(int percent) {
        int count = (int) Math.ceil(list.size() * percent / 100.0);
        return list.stream().sorted(Comparator.reverseOrder()).limit(count).collect(Collectors.toList());
    }

    public static void main(String[] args) {
        List<BigDecimal> list = new ArrayList<>();
        // Add elements to the list

        BigDecimalOperations ops = new BigDecimalOperations(list);
        System.out.println("Sum: " + ops.sum());
        System.out.println("Average: " + ops.average());
        System.out.println("Top 10%: " + ops.topPercent(10));
    }
}

class BigDecimalOperationsTest {
    @Test
    public void testOperations() {
        List<BigDecimal> list = Arrays.asList(BigDecimal.valueOf(1), BigDecimal.valueOf(2), BigDecimal.valueOf(3));
        BigDecimalOperations ops = new BigDecimalOperations(list);

        Assertions.assertEquals(BigDecimal.valueOf(6), ops.sum());
        Assertions.assertEquals(BigDecimal.valueOf(2), ops.average());
        Assertions.assertEquals(Arrays.asList(BigDecimal.valueOf(3)), ops.topPercent(10));
    }
}

@BenchmarkMode(Mode.AverageTime)
@OutputTimeUnit(TimeUnit.MILLISECONDS)
@State(Scope.Thread)
class BigDecimalOperationsBenchmark {
    List<BigDecimal> randomList;
    List<BigDecimal> sortedAscList;
    List<BigDecimal> sortedDescList;

    @Setup
    public void setup() {
        randomList = generateRandomList(100_000_000);
        sortedAscList = new ArrayList<>(randomList);
        sortedAscList.sort(BigDecimal::compareTo);
        sortedDescList = new ArrayList<>(randomList);
        sortedDescList.sort(Comparator.reverseOrder());
    }

    @Benchmark
    public void benchmarkRandomList() {
        BigDecimalOperations ops = new BigDecimalOperations(randomList);
        ops.sum();
        ops.average();
        ops.topPercent(10);
    }

    @Benchmark
    public void benchmarkSortedAscList() {
        BigDecimalOperations ops = new BigDecimalOperations(sortedAscList);
        ops.sum();
        ops.average();
        ops.topPercent(10);
    }

    @Benchmark
    public void benchmarkSortedDescList() {
        BigDecimalOperations ops = new BigDecimalOperations(sortedDescList);
        ops.sum();
        ops.average();
        ops.topPercent(10);
    }

    private List<BigDecimal> generateRandomList(int size) {
        Random rand = new Random();
        List<BigDecimal> list = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            list.add(BigDecimal.valueOf(rand.nextDouble() * size));
        }
        return list;
    }
}
*/