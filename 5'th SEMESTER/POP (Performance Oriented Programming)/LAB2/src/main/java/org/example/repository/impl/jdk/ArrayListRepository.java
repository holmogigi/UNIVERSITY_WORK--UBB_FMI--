package org.example.repository.impl.jdk;

import org.example.repository.InMemoryRepository;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class ArrayListRepository<T> implements InMemoryRepository<T> {
    private final List<T> list;

    public ArrayListRepository() {
        this.list = new ArrayList<T>();
    }

    public ArrayListRepository(List<T> list) {
        this.list = list;
    }

    @Override
    public void add(T obj) {
        this.list.add(obj);
    }

    @Override
    public void addAll(Collection<T> objects) {
        this.list.addAll(objects);
    }

    @Override
    public boolean contains(T obj) {
        return this.list.contains(obj);
    }

    @Override
    public void remove(T obj) {
        this.list.remove(obj);
    }

    @Override
    public void clear() {
        this.list.clear();
    }
}
