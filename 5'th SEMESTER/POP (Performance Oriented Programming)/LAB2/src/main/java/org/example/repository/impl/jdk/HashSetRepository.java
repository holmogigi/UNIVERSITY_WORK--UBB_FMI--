package org.example.repository.impl.jdk;

import org.example.repository.InMemoryRepository;

import java.util.Collection;
import java.util.HashSet;

public class HashSetRepository<T> implements InMemoryRepository<T> {
    private final HashSet<T> hashSet;

    public HashSetRepository() {
        this.hashSet = new HashSet<>();
    }

    public HashSetRepository(HashSet<T> hashSet) {
        this.hashSet = hashSet;
    }

    @Override
    public void add(T obj) {
        this.hashSet.add(obj);
    }

    @Override
    public void addAll(Collection<T> objects) {
        this.hashSet.addAll(objects);
    }

    @Override
    public boolean contains(T obj) {
        return this.hashSet.contains(obj);
    }

    @Override
    public void remove(T obj) {
        this.hashSet.remove(obj);
    }

    @Override
    public void clear() {
        this.hashSet.clear();
    }
}
