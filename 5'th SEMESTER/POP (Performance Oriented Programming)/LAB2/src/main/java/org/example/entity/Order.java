package org.example.entity;

import java.util.Objects;

public class Order implements Comparable<Order>, Entity {
    private int id;

    private int price;

    private int quantity;

    public Order(int id, int price, int quantity) {
        this.id = id;
        this.price = price;
        this.quantity = quantity;
    }

    public String toString(){
        return "Order(" + this.id + ", " + this.price + ", " + this.quantity + ")";
    }

    @Override
    public int compareTo(Order o){
        int valueFirst = this.price * this.quantity;
        int valueSecond = o.price * o.quantity;
        return Integer.compare(valueFirst, valueSecond);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Order order = (Order) o;
        return id == order.id;
    }

    @Override
    public int hashCode() {
        return Objects.hash(id);
    }

    @Override
    public Integer getEntityId() {
        return this.id;
    }

    public int getId() {
        return id;
    }

    public int getPrice() {
        return price;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }
}

