package stream_benchmarks;

import it.unimi.dsi.fastutil.doubles.DoubleArrayList;
import org.example.streams.ObjectStream;
import org.openjdk.jmh.annotations.*;
import org.openjdk.jmh.infra.Blackhole;
import org.openjdk.jmh.runner.Runner;
import org.openjdk.jmh.runner.RunnerException;
import org.openjdk.jmh.runner.options.Options;
import org.openjdk.jmh.runner.options.OptionsBuilder;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.concurrent.TimeUnit;

public class StreamBenchmarks {
    @State(Scope.Benchmark)
    public static class DoubleAscendingElemsEP {
        public List<Double> doubleList = new ArrayList<>();

        public ObjectStream<Double> doubleObjectStream = new ObjectStream<>();

        @Setup(Level.Invocation)
        public void setup() {
            this.doubleList.clear();

            for(int i = 1; i <= 100000000; i++){
                doubleList.add((double) i);
            }
        }
    }

    @State(Scope.Benchmark)
    public static class DoubleDescendingElemsEP {
        public List<Double> doubleList = new ArrayList<>();

        public ObjectStream<Double> doubleObjectStream = new ObjectStream<>();

        @Setup(Level.Invocation)
        public void setup() {
            doubleList.clear();

            for(int i = 100000000; i >= 1; i--){
                doubleList.add((double) i);
            }
        }
    }

    @State(Scope.Benchmark)
    public static class DoubleRandomElemsEP {
        public List<Double> doubleList = new ArrayList<>();

        public ObjectStream<Double> doubleObjectStream = new ObjectStream<>();

        @Setup(Level.Invocation)
        public void setup() {
            Random random = new Random();
            int max = 20000;
            int min = 1;
            Random rand = new Random();

            doubleList.clear();

            for(int i = 1; i <= 100000000; i++){
                Double value = (double) (rand.nextInt((max - min) + 1) + min);
                doubleList.add(value);
            }
        }
    }

    @State(Scope.Benchmark)
    public static class PrimitiveDoubleAscendingElemsEP {
        public DoubleArrayList doubleArrayList = new DoubleArrayList();

        public ObjectStream<Double> doubleObjectStream = new ObjectStream<>();

        @Setup(Level.Invocation)
        public void setup() {
            doubleArrayList.clear();

            for(int i = 1; i <= 100000000; i++){
                doubleArrayList.add(i);
            }
        }
    }

    @State(Scope.Benchmark)
    public static class PrimitiveDoubleDescendingElemsEP {
        public DoubleArrayList doubleArrayList = new DoubleArrayList();

        public ObjectStream<Double> doubleObjectStream = new ObjectStream<>();

        @Setup(Level.Invocation)
        public void setup() {
            doubleArrayList.clear();

            for(int i = 100000000; i >= 1; i--){
                doubleArrayList.add(i);
            }
        }
    }

    @State(Scope.Benchmark)
    public static class PrimitiveDoubleRandomElemsEP {
        public DoubleArrayList doubleArrayList = new DoubleArrayList();

        public ObjectStream<Double> doubleObjectStream = new ObjectStream<>();

        @Setup(Level.Invocation)
        public void setup() {
            Random random = new Random();
            int max = 20000;
            int min = 1;
            Random rand = new Random();

            doubleArrayList.clear();

            for(int i = 1; i <= 100000000; i++){
                double value = rand.nextInt((max - min) + 1) + min;
                doubleArrayList.add(value);
            }
        }
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void doubleAscendingElemsSumBM(DoubleAscendingElemsEP executionPlan, Blackhole blackhole) {
        List<Double> source = executionPlan.doubleList;
        Double sum = executionPlan.doubleObjectStream.sum(source);

        blackhole.consume(sum);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void doubleAscendingElemsAvgBM(DoubleAscendingElemsEP executionPlan, Blackhole blackhole) {
        List<Double> source = executionPlan.doubleList;
        Double average = executionPlan.doubleObjectStream.average(source);

        blackhole.consume(average);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void doubleAscendingElemsTopTenBM(DoubleAscendingElemsEP executionPlan, Blackhole blackhole) {
        List<Double> source = executionPlan.doubleList;
        List<Double> result = executionPlan.doubleObjectStream.topTenPercent(source);

        blackhole.consume(result);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void doubleDescendingElemsSumBM(DoubleDescendingElemsEP executionPlan, Blackhole blackhole) {
        List<Double> source = executionPlan.doubleList;
        Double sum = executionPlan.doubleObjectStream.sum(source);

        blackhole.consume(sum);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void doubleDescendingElemsAvgBM(DoubleDescendingElemsEP executionPlan, Blackhole blackhole) {
        List<Double> source = executionPlan.doubleList;
        Double avg = executionPlan.doubleObjectStream.average(source);

        blackhole.consume(avg);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void doubleDescendingElemsTopTenBM(DoubleDescendingElemsEP executionPlan, Blackhole blackhole) {
        List<Double> source = executionPlan.doubleList;
        List<Double> result = executionPlan.doubleObjectStream.topTenPercent(source);

        blackhole.consume(result);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void doubleRandomElemsSumBM(DoubleRandomElemsEP executionPlan, Blackhole blackhole) {
        List<Double> source = executionPlan.doubleList;
        Double sum = executionPlan.doubleObjectStream.sum(source);

        blackhole.consume(sum);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void doubleRandomElemsAvgBM(DoubleRandomElemsEP executionPlan, Blackhole blackhole) {
        List<Double> source = executionPlan.doubleList;
        Double avg = executionPlan.doubleObjectStream.average(source);

        blackhole.consume(avg);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void doubleRandomElemsTopTenBM(DoubleRandomElemsEP executionPlan, Blackhole blackhole) {
        List<Double> source = executionPlan.doubleList;
        List<Double> result = executionPlan.doubleObjectStream.topTenPercent(source);

        blackhole.consume(result);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void primitiveDoubleAscendingElemsSumBM(PrimitiveDoubleAscendingElemsEP executionPlan, Blackhole blackhole) {
        List<Double> source = executionPlan.doubleArrayList;
        Double sum = executionPlan.doubleObjectStream.sum(source);

        blackhole.consume(sum);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void primitiveDoubleAscendingElemsAvgBM(PrimitiveDoubleAscendingElemsEP executionPlan, Blackhole blackhole) {
        List<Double> source = executionPlan.doubleArrayList;
        Double avg = executionPlan.doubleObjectStream.average(source);

        blackhole.consume(avg);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void primitiveDoubleAscendingElemsTopTenBM(PrimitiveDoubleAscendingElemsEP executionPlan, Blackhole blackhole) {
        List<Double> source = executionPlan.doubleArrayList;
        List<Double> result = executionPlan.doubleObjectStream.topTenPercent(source);

        blackhole.consume(result);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void primitiveDoubleDescendingElemsSumBM(PrimitiveDoubleDescendingElemsEP executionPlan, Blackhole blackhole) {
        List<Double> source = executionPlan.doubleArrayList;
        Double sum = executionPlan.doubleObjectStream.sum(source);

        blackhole.consume(sum);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void primitiveDoubleDescendingElemsAvgBM(PrimitiveDoubleDescendingElemsEP executionPlan, Blackhole blackhole) {
        List<Double> source = executionPlan.doubleArrayList;
        Double avg = executionPlan.doubleObjectStream.average(source);

        blackhole.consume(avg);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void primitiveDoubleDescendingElemsTopTenBM(PrimitiveDoubleDescendingElemsEP executionPlan, Blackhole blackhole) {
        List<Double> source = executionPlan.doubleArrayList;
        List<Double> result = executionPlan.doubleObjectStream.topTenPercent(source);

        blackhole.consume(result);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void primitiveDoubleRandomElemsSumBM(PrimitiveDoubleRandomElemsEP executionPlan, Blackhole blackhole) {
        List<Double> source = executionPlan.doubleArrayList;
        Double sum = executionPlan.doubleObjectStream.sum(source);

        blackhole.consume(sum);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void primitiveDoubleRandomElemsAvgBM(PrimitiveDoubleRandomElemsEP executionPlan, Blackhole blackhole) {
        List<Double> source = executionPlan.doubleArrayList;
        Double avg = executionPlan.doubleObjectStream.average(source);

        blackhole.consume(avg);
    }

    @Benchmark
    @Fork(1)
    @Warmup(iterations = 3, time = 2, timeUnit = TimeUnit.SECONDS)
    @Measurement(iterations = 5, time = 2, timeUnit = TimeUnit.SECONDS)
    public void primitiveDoubleRandomElemsTopTenBM(PrimitiveDoubleRandomElemsEP executionPlan, Blackhole blackhole) {
        List<Double> source = executionPlan.doubleArrayList;
        List<Double> result = executionPlan.doubleObjectStream.topTenPercent(source);

        blackhole.consume(result);
    }

    public static void main(String[] args) throws RunnerException {
        Options opt = new OptionsBuilder()
                .include(StreamBenchmarks.class.getSimpleName())
                .forks(1)
                .measurementIterations(5)  // Adjust this value
                .warmupIterations(3)       // Adjust this value
                .build();
        new Runner(opt).run();
    }

}
