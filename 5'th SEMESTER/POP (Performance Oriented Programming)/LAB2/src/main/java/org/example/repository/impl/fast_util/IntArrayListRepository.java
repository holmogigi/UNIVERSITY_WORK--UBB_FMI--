package org.example.repository.impl.fast_util;

import it.unimi.dsi.fastutil.ints.IntArrayList;
import org.example.repository.InMemoryRepository;

import java.util.Collection;

public class IntArrayListRepository implements InMemoryRepository<Integer> {
    private final IntArrayList intArrayList;

    public IntArrayListRepository() {
        this.intArrayList = new IntArrayList();
    }

    public IntArrayListRepository(IntArrayList intArrayList) {
        this.intArrayList = intArrayList;
    }

    @Override
    public void add(Integer obj) {
        this.intArrayList.add(obj.intValue());
    }

    @Override
    public void addAll(Collection<Integer> objects) {
        this.intArrayList.addAll(objects);
    }

    @Override
    public boolean contains(Integer obj) {
        return this.intArrayList.contains(obj.intValue());
    }

    @Override
    public void remove(Integer obj) {
        this.intArrayList.rem(obj);
    }

    @Override
    public void clear() {
        this.intArrayList.clear();
    }
}
