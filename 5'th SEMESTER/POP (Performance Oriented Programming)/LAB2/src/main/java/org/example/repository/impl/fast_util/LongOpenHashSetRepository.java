package org.example.repository.impl.fast_util;

import it.unimi.dsi.fastutil.longs.LongOpenHashSet;
import org.example.repository.InMemoryRepository;

import java.util.Collection;

public class LongOpenHashSetRepository implements InMemoryRepository<Long> {
    private final LongOpenHashSet longOpenHashSet;

    public LongOpenHashSetRepository() {
        this.longOpenHashSet = new LongOpenHashSet();
    }

    public LongOpenHashSetRepository(LongOpenHashSet longOpenHashSet) {
        this.longOpenHashSet = longOpenHashSet;
    }

    @Override
    public void add(Long obj) {
        this.longOpenHashSet.add(obj.longValue());
    }

    @Override
    public void addAll(Collection<Long> objects) {
        this.longOpenHashSet.addAll(objects);
    }

    @Override
    public boolean contains(Long obj) {
        return this.longOpenHashSet.contains(obj.longValue());
    }

    @Override
    public void remove(Long obj) {
        this.longOpenHashSet.remove(obj.longValue());
    }

    @Override
    public void clear() {
        this.longOpenHashSet.clear();
    }
}
