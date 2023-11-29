package org.example.streams;

import org.example.helpers.NumberHelpers;

import java.util.Collection;
import java.util.List;
import java.util.stream.Collectors;

public class ObjectStream<T extends Number> {
    public T sum(Collection<T> elems) {
        return elems.stream()
                .reduce(NumberHelpers::handleSum)
                .orElse(null);
    }

    public T average(Collection<T> elems) {
        return elems.stream()
                .reduce(NumberHelpers::handleSum)
                .map(t -> (T) NumberHelpers.handleAverage(t, elems.size()))
                .orElse(null);
    }

    public List<T> topTenPercent(Collection<T> elems) {
        return elems.stream()
                .sorted(NumberHelpers::handleComparison)
                .limit(elems.size() / 10)
                .collect(Collectors.toList());
    }
}
