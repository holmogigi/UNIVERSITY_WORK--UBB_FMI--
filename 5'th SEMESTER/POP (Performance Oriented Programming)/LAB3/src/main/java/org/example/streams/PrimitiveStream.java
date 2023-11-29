package org.example.streams;

import it.unimi.dsi.fastutil.doubles.DoubleArrayList;

import java.util.List;
import java.util.stream.Collectors;

public class PrimitiveStream {
    public double sum(DoubleArrayList doubles) {
        return doubles.stream()
                .reduce(Double::sum)
                .orElse(0.0);
    }

    public double average(DoubleArrayList doubles) {
        return doubles.stream()
                .reduce(Double::sum)
                .map(val -> val / doubles.size())
                .orElse(0.0);
    }

    public List<Double> topTenPercent(DoubleArrayList doubles) {
        return doubles.stream()
                .sorted((d1, d2) -> {
                    if (d1 > d2) return -1;
                    if (d1 < d2) return 1;
                    return 0;
                })
                .limit(doubles.size() / 10)
                .collect(Collectors.toList());
    }
}
