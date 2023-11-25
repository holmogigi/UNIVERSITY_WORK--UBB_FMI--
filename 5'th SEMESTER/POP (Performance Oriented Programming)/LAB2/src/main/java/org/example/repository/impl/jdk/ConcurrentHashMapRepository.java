package org.example.repository.impl.jdk;

import org.example.entity.Entity;
import org.example.repository.InMemoryRepository;

import java.util.Collection;
import java.util.concurrent.ConcurrentHashMap;

public class ConcurrentHashMapRepository<T extends Entity> implements InMemoryRepository<T> {
    private final ConcurrentHashMap<Integer, T> concurrentHashMap;

    public ConcurrentHashMapRepository() {
        this.concurrentHashMap = new ConcurrentHashMap<>();
    }

    public ConcurrentHashMapRepository(ConcurrentHashMap<Integer, T> concurrentHashMap) {
        this.concurrentHashMap = concurrentHashMap;
    }

    @Override
    public void add(T obj) {
        this.concurrentHashMap.put(obj.getEntityId(), obj);
    }

    @Override
    public void addAll(Collection<T> objects) {
        for (T obj : objects) {
            this.concurrentHashMap.put(obj.getEntityId(), obj);
        }
    }

    @Override
    public boolean contains(T obj) {
        return this.concurrentHashMap.containsValue(obj);
    }

    @Override
    public void remove(T obj) {
        this.concurrentHashMap.remove(obj.getEntityId());
    }

    @Override
    public void clear() {
        this.concurrentHashMap.clear();
    }
}
