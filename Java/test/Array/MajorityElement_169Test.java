package Array;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class MajorityElement_169Test {

    @Test
    void majorityElement1() {
        var s = new MajorityElement_169();
        var d = new int[]{3, 2, 3};
        assertEquals(3, s.majorityElement(d));
    }

    @Test
    void majorityElement2() {
        var s = new MajorityElement_169();
        var d = new int[]{2, 2, 1, 1, 1, 2, 2};
        assertEquals(2, s.majorityElement(d));
    }
}