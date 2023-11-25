package org.example.repository.impl.fast_util;

import org.eclipse.collections.impl.map.mutable.primitive.IntIntHashMap;
import org.example.repository.InMemoryRepository;

import java.util.Collection;

public class IntIntHashMapRepository implements InMemoryRepository<Integer> {
    private final IntIntHashMap items;

    public IntIntHashMapRepository() {
        this.items = new IntIntHashMap();
    }

    public IntIntHashMapRepository(IntIntHashMap items) {
        this.items = items;
    }

    @Override
    public void add(Integer obj) {
        this.items.put(obj, obj);
    }

    @Override
    public void addAll(Collection<Integer> objects) {
        for (Integer integer : objects) {
            this.items.put(integer, integer);
        }
    }

    @Override
    public boolean contains(Integer obj) {
        return this.items.contains(obj);
    }

    @Override
    public void remove(Integer obj) {
        this.items.remove(obj);
    }

    @Override
    public void clear() {
        this.items.clear();
    }
}
