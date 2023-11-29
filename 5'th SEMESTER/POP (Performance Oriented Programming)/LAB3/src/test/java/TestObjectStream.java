/*
import org.example.streams.ObjectStream;
import org.hamcrest.MatcherAssert;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

import static org.hamcrest.Matchers.is;

public class TestObjectStream {
    private ObjectStream<BigInteger> bigIntegerObjectStream;
    private ObjectStream<Double> doubleObjectStream;

    private List<BigInteger> bigIntegerList;
    private List<Double> doubleList;

    @BeforeEach
    public void setup() {
        this.bigIntegerObjectStream = new ObjectStream<>();
        this.doubleObjectStream  = new ObjectStream<>();
        this.bigIntegerList = new ArrayList<>();
        this.doubleList = new ArrayList<>();
    }

    /// BigInteger Stream Tests ///
    @Test
    public void bigIntegerStreamAdd() {
        ///declarations
        int i;

        ///prepare
        for (i = 0; i < 100; i++) {
            BigInteger value = BigInteger.valueOf(i);
            this.bigIntegerList.add(value);
        }

        ///action
        BigInteger sum = this.bigIntegerObjectStream.sum(this.bigIntegerList);

        ///assert
        BigInteger expectedValue = BigInteger.valueOf(4950);
        MatcherAssert.assertThat(sum, is(expectedValue));
    }

    @Test
    public void bigIntegerStreamAverage() {
        ///declarations
        int i;

        ///prepare
        for (i = 0; i < 100; i++) {
            BigInteger value = BigInteger.valueOf(i);
            this.bigIntegerList.add(value);
        }

        ///action
        BigInteger average = this.bigIntegerObjectStream.average(this.bigIntegerList);

        ///assert
        BigInteger expectedValue = BigInteger.valueOf(49);
        MatcherAssert.assertThat(average, is(expectedValue));
    }

    @Test
    public void bigIntegerStreamTopTenPercent() {
        ///declarations
        int i;

        ///prepare
        for (i = 0; i < 100; i++) {
            BigInteger value = BigInteger.valueOf(i);
            this.bigIntegerList.add(value);
        }

        ///action
        List<BigInteger> result = this.bigIntegerObjectStream.topTenPercent(this.bigIntegerList);

        ///assert
        BigInteger expectedValue = BigInteger.valueOf(0);
        BigInteger stepValue = BigInteger.valueOf(1);

        for (BigInteger bigInteger : result) {
            MatcherAssert.assertThat(bigInteger, is(expectedValue));
            expectedValue = expectedValue.add(stepValue);
        }
    }

    /// Double Stream Tests ///

    @Test
    public void doubleStreamAdd() {
        ///declarations
        int i;

        ///prepare
        for (i = 0; i < 100; i++) {
            Double value = (double) i;
            this.doubleList.add(value);
        }

        ///action
        Double result = this.doubleObjectStream.sum(this.doubleList);

        ///assert
        Double expectedValue = 4950.0;
        MatcherAssert.assertThat(result, is(expectedValue));
    }

    @Test
    public void doubleStreamAverage() {
        ///declarations
        int i;

        ///prepare
        for (i = 0; i < 100; i++) {
            Double value = (double) i;
            this.doubleList.add(value);
        }

        ///action
        Double average = this.doubleObjectStream.average(this.doubleList);

        ///assert
        Double expectedValue = 49.5;
        MatcherAssert.assertThat(average, is(expectedValue));
    }

    @Test
    public void doubleStreamTopTenPercent() {
        ///declarations
        int i;

        ///prepare
        for (i = 0; i < 100; i++) {
            Double value = (double) i;
            this.doubleList.add(value);
        }

        ///action
        List<Double> result = this.doubleObjectStream.topTenPercent(this.doubleList);

        ///assert
        double expectedValue = 0.0;
        double stepValue = 1.0;

        for (Double element : result) {
            MatcherAssert.assertThat(element, is(expectedValue));
            expectedValue += stepValue;
        }
    }
}
*/