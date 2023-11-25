package org.example.repository;

import java.util.Collection;

public interface InMemoryRepository<T> {
    void add(T obj);

    void addAll(Collection<T> objects);

    boolean contains(T obj);

    void remove(T obj);

    void clear();

}
