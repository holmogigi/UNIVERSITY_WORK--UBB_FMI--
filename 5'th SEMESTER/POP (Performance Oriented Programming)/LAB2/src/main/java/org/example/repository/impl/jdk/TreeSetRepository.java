package org.example.repository.impl.jdk;

import org.example.repository.InMemoryRepository;

import java.util.Collection;
import java.util.TreeSet;

public class TreeSetRepository<T> implements InMemoryRepository<T> {
    private final TreeSet<T> treeSet;

    public TreeSetRepository() {
        this.treeSet = new TreeSet<>();
    }

    public TreeSetRepository(TreeSet<T> treeSet) {
        this.treeSet = treeSet;
    }

    @Override
    public void add(T obj) {
        this.treeSet.add(obj);
    }

    @Override
    public void addAll(Collection<T> objects) {
        this.treeSet.addAll(objects);
    }

    @Override
    public boolean contains(T obj) {
        return this.treeSet.contains(obj);
    }

    @Override
    public void remove(T obj) {
        this.treeSet.remove(obj);
    }

    @Override
    public void clear() {
        this.treeSet.clear();
    }
}
