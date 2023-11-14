

import org.example.controller.CalculatorController;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class CalculatorControllerTest {

    @Test
    public void testAdd
            () {
        double result = CalculatorController.Calculate("+", 5, 3);
        assertEquals(8.0, result, 0.01); // 5 + 3 = 8
    }

    @Test
    public void testSubtract() {
        double result = CalculatorController.Calculate("-", 10, 4);
        assertEquals(6.0, result, 0.01); // 10 - 4 = 6
    }

    @Test
    public void testDivide() {
        double result = CalculatorController.Calculate("/", 15, 3);
        assertEquals(5.0, result, 0.01); // 15 / 3 = 5
    }

    @Test
    public void testMultiply() {
        double result = CalculatorController.Calculate("*", 6, 7);
        assertEquals(42.0, result, 0.01); // 6 * 7 = 42
    }

    @Test
    public void testMin() {
        double result = CalculatorController.Calculate("min", 9, 11);
        assertEquals(9.0, result, 0.01); // min(9, 11) = 9
    }

    @Test
    public void testMax() {
        double result = CalculatorController.Calculate("max", 13, 8);
        assertEquals(13.0, result, 0.01); // max(13, 8) = 13
    }

    @Test
    public void testSqrt() {
        double result = CalculatorController.Calculate("sqrt", 25, 0);
        assertEquals(5.0, result, 0.01); // sqrt(25) = 5
    }
}