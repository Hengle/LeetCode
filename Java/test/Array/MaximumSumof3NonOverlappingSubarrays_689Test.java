package Array;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaximumSumof3NonOverlappingSubarrays_689Test {

    @Test
    void maxSumOfThreeSubarrays() {
        var s = new MaximumSumof3NonOverlappingSubarrays_689();
        var v = new int[]{1,2,1,2,6,7,5,1};
        var ans = s.maxSumOfThreeSubarrays(v, 2);
        System.out.printf("%d %d %d\n", ans[0], ans[1], ans[2]);
    }
    @Test
    void maxSumOfThreeSubarrays2() {
        var s = new MaximumSumof3NonOverlappingSubarrays_689();
        var v = new int[]{7,13,20,19,19,2,10,1,1,19};
        var ans = s.maxSumOfThreeSubarrays(v, 3);
        System.out.printf("%d %d %d\n", ans[0], ans[1], ans[2]);
    }

}