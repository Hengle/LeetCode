package Array;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class JumpGame_55 {
    public boolean canJump(int[] nums) {
       int maxReach = 0;
       for (int i = 0; i < nums.length; ++i) {
           if (i  > maxReach) {
               return false;
           }
           maxReach = Math.max(maxReach, i + nums[i]);
       }
       return true;
    }
}
