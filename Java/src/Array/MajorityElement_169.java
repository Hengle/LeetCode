package Array;

public class MajorityElement_169 {
    public int majorityElement(int[] nums) {
        int count = 0, num = 0;
        for (int v : nums) {
            if (count == 0) {
                num = v;
                count++;
            } else if (v == num) {
                count++;
            } else {
                count--;
            }
        }
        return num;
    }
}
