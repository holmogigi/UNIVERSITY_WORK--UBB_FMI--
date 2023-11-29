/*
import it.unimi.dsi.fastutil.doubles.DoubleArrayList;
import org.example.streams.PrimitiveStream;
import org.hamcrest.MatcherAssert;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.List;

import static org.hamcrest.Matchers.is;

public class TestPrimitiveStream {
    private PrimitiveStream primitiveStream;

    private DoubleArrayList doubleArrayList;

    @BeforeEach
    public void setup() {
        this.primitiveStream = new PrimitiveStream();
        this.doubleArrayList = new DoubleArrayList();
    }

    @Test
    public void primitiveStreamSum() {
        ///declarations
        int i;

        ///prepare
        for (i = 0; i < 100; i++) {
            this.doubleArrayList.add(i);
        }

        ///action
        double result = this.primitiveStream.sum(this.doubleArrayList);

        ///assert
        double expectedValue = 4950.0;
        MatcherAssert.assertThat(result, is(expectedValue));
    }

    @Test
    public void primitiveStreamAverage() {
        ///declarations
        int i;

        ///prepare
        for (i = 0; i < 100; i++) {
            this.doubleArrayList.add(i);
        }

        ///action
        double average = this.primitiveStream.average(this.doubleArrayList);

        ///assert
        double expectedValue = 49.5;
        MatcherAssert.assertThat(average, is(expectedValue));
    }

    @Test
    public void primitiveStreamTopTenPercent() {
        ///declarations
        int i;

        ///prepare
        for (i = 0; i < 100; i++) {
            this.doubleArrayList.add(i);
        }

        ///action
        List<Double> result = this.primitiveStream.topTenPercent(this.doubleArrayList);

        ///assert
        double expectedValue = 99.0;
        double stepValue = 1.0;

        for (Double element : result) {
            MatcherAssert.assertThat(element, is(expectedValue));
            expectedValue -= stepValue;
        }
    }
}
*/