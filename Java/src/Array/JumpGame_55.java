package Array;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class JumpGame_55 {
    public boolean canJump(int[] nums) {
       int leftMostCanReachEnd = nums.length - 1;
       for (int i = leftMostCanReachEnd - 1; i >=0; --i) {
           if (i + nums[i] >= leftMostCanReachEnd) {
               leftMostCanReachEnd = i;
           }
       }
        return leftMostCanReachEnd == 0;
    }
}
