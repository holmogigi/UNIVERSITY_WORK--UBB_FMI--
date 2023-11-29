package org.example.helpers;

import java.math.BigInteger;

@SuppressWarnings("unchecked")
public class NumberHelpers {

    public static <T extends Number> T handleSum(T elem1, T elem2) {
        T sum = null;

        if (elem1 instanceof BigInteger && elem2 instanceof BigInteger) {
            BigInteger convertedElem1 = (BigInteger) elem1;
            BigInteger convertedElem2 = (BigInteger) elem2;

            sum = (T) NumberHelpers.addNums(convertedElem1, convertedElem2);
        }

        if (elem1 instanceof Double && elem2 instanceof Double) {
            Double convertedElem1 = (Double) elem1;
            Double convertedElem2 = (Double) elem2;

            sum = (T) NumberHelpers.addNums(convertedElem1, convertedElem2);
        }

        return sum;
    }

    public static <T extends Number> T handleAverage(T elem1, T elem2) {
        T sum = null;

        if (elem1 instanceof BigInteger && elem2 instanceof Integer) {
            BigInteger convertedElem1 = (BigInteger) elem1;
            Integer convertedElem2 = (Integer) elem2;

            sum = (T) NumberHelpers.numsAverage(convertedElem1, convertedElem2);
        }

        if (elem1 instanceof Double && elem2 instanceof Integer) {
            Double convertedElem1 = (Double) elem1;
            Integer convertedElem2 = (Integer) elem2;

            sum = (T) NumberHelpers.numsAverage(convertedElem1, convertedElem2);
        }

        return sum;
    }

    public static <T extends Number> int handleComparison(T elem1, T elem2) {
        if (elem1 instanceof BigInteger && elem2 instanceof BigInteger) {
            BigInteger convertedElem1 = (BigInteger) elem1;
            BigInteger convertedElem2 = (BigInteger) elem2;

            return NumberHelpers.compareNums(convertedElem1, convertedElem2);
        }

        if (elem1 instanceof Double && elem2 instanceof Double) {
            Double convertedElem1 = (Double) elem1;
            Double convertedElem2 = (Double) elem2;

            return NumberHelpers.compareNums(convertedElem1, convertedElem2);
        }

        return 0;
    }

    public static BigInteger addNums(BigInteger a, BigInteger b) {
        return a.add(b);
    }

    public static Double addNums(Double a, Double b) {
        return a + b;
    }

    public static BigInteger numsAverage(BigInteger sum, Integer size) {
        return sum.divide(BigInteger.valueOf(size));
    }

    public static Double numsAverage(Double sum, Integer size) {
        return sum / size;
    }

    public static int compareNums(BigInteger elem1, BigInteger elem2) {
        return elem1.compareTo(elem2);
    }

    public static int compareNums(Double elem1, Double elem2) {
        return elem1.compareTo(elem2);
    }
}
