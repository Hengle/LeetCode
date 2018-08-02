package Array;

import java.util.ArrayList;
import java.util.List;

public class MajorityElement_II_229 {
    public List<Integer> majorityElement(int[] nums) {
        if (nums == null || nums.length < 1) {
            return new ArrayList<Integer>();
        }
        int len = nums.length;
        List<Integer> ans = new ArrayList<Integer>();
        int count1 = 0, num1 = 0, count2 = 0, num2 = 0;
        for (int v : nums) {
            if (v == num1) {
                count1++;
            } else if (v == num2) {
                count2++;
            } else if (count1 == 0) {
                num1 = v;
                count1++;
            } else if (count2 == 0) {
                num2 = v;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int v : nums) {
            if (v == num1) {
                count1++;
            } else if (v == num2) {
                count2++;
            }
        }
        if (count1 > len / 3) {
            ans.add(num1);
        }
        if (count2 > len / 3) {
            ans.add(num2);
        }
        return ans;
    }
}
