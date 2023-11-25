package org.example.repository.impl.eclipse_collections;

import org.eclipse.collections.api.list.MutableList;
import org.eclipse.collections.impl.list.mutable.FastList;
import org.example.repository.InMemoryRepository;

import java.util.Collection;

public class MutableListRepository<T> implements InMemoryRepository<T> {
    private final MutableList<T> mutableList;

    public MutableListRepository() {
        this.mutableList = FastList.newList();
    }

    @Override
    public void add(T obj) {
        this.mutableList.add(obj);
    }

    @Override
    public void addAll(Collection<T> objects) {
        this.mutableList.addAll(objects);
    }

    @Override
    public boolean contains(T obj) {
        return this.mutableList.contains(obj);
    }

    @Override
    public void remove(T obj) {
        this.mutableList.remove(obj);
    }

    @Override
    public void clear() {
        this.mutableList.clear();
    }
}
