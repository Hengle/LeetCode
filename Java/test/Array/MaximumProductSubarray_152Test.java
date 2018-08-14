package Array;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaximumProductSubarray_152Test {

    @Test
    void maxProduct() {
        var s = new MaximumProductSubarray_152();
        var v = new int[] {2,3,-2, 4};
        assertEquals(6, s.maxProduct(v));
    }
    @Test
    void maxProduct2() {
        var s = new MaximumProductSubarray_152();
        var v = new int[] {-2, 0, -1};
        assertEquals(0, s.maxProduct(v));
    }
    @Test
    void maxProduct3() {
        var s = new MaximumProductSubarray_152();
        var v = new int[] {0, 1, -1};
        assertEquals(1, s.maxProduct(v));
    }
    @Test
    void maxProduct4() {
        var s = new MaximumProductSubarray_152();
        var v = new int[] {-2};
        assertEquals(-2, s.maxProduct(v));
    }

}