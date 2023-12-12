package org.example;

import java.util.concurrent.ExecutionException;

public class Main {
    public static void main(String[] args) throws InterruptedException, ExecutionException {

        Polynomial p = new Polynomial(7000);
        Polynomial q = new Polynomial(7000);

        //System.out.println(multiplication1(p, q).toString() + "\n");
        multiplication1(p, q);

        //System.out.println(multiplication2(p, q).toString() + "\n");
        multiplication2(p, q);

        //Karatsuba
        //System.out.println(multiplication3(p, q).toString() + "\n");
        multiplication3(p, q);

        //System.out.println(multiplication4(p, q).toString() + "\n");
        multiplication4(p, q);
    }

    private static Polynomial multiplication4(Polynomial p, Polynomial q) throws ExecutionException,
            InterruptedException {
        long startTime = System.currentTimeMillis();
        Polynomial result4 = Operations.multiplicationKaratsubaParallelizedForm(p, q, 4);
        long endTime = System.currentTimeMillis();
        System.out.println("Karatsuba parallel multiplication of polynomials: ");
        System.out.println("Exec time : " + (endTime - startTime) + " ms");
        return result4;
    }

    private static Polynomial multiplication3(Polynomial p, Polynomial q) {
        long startTime = System.currentTimeMillis();
        Polynomial result3 = Operations.multiplicationKaratsubaSequentialForm(p, q);
        long endTime = System.currentTimeMillis();
        System.out.println("Karatsuba sequential multiplication of polynomials: ");
        System.out.println("Exec time : " + (endTime - startTime) + " ms");
        return result3;
    }

    private static Polynomial multiplication2(Polynomial p, Polynomial q) throws InterruptedException {
        long startTime = System.currentTimeMillis();
        Polynomial result2 = Operations.multiplicationParallelizedForm(p, q, 5);
        long endTime = System.currentTimeMillis();
        System.out.println("Simple parallel multiplication of polynomials: ");
        System.out.println("Exec time : " + (endTime - startTime) + " ms");
        return result2;
    }

    private static Polynomial multiplication1(Polynomial p, Polynomial q) {
        long startTime = System.currentTimeMillis();
        Polynomial result1 = Operations.multiplicationSequentialForm(p, q);
        long endTime = System.currentTimeMillis();
        System.out.println("Simple sequential multiplication of polynomials: ");
        System.out.println("Exec time : " + (endTime - startTime) + " ms");
        return result1;
    }
}