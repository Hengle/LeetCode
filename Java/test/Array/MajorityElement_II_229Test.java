package Array;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class MajorityElement_II_229Test {

    @Test
    void majorityElement1() {
        var s = new MajorityElement_II_229();
        var v = new int[]{3,2,3};
        List<Integer> ans = s.majorityElement(v);
        List<Integer> expect = new ArrayList<Integer>();
        expect.add(3);

        assertEquals(expect, ans);
    }
    @Test
    void majorityElement2() {
        var s = new MajorityElement_II_229();
        var v = new int[]{1,1,1,3,3,2,2,2};
        List<Integer> ans = s.majorityElement(v);
        List<Integer> expect = new ArrayList<Integer>();
        expect.add(1);
        expect.add(2);

        assertEquals(expect, ans);
    }
}