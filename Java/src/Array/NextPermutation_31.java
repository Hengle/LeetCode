package Array;

public class NextPermutation_31 {
    public void reverse(int[] nums, int start, int end) {
        if (start >= end) return;
        int m = start + (end - start) / 2;
        int t = 0;
        for (int i = start; i <= m; ++i) {
            t = nums[i];
            nums[i] = nums[end - (i - start)];
            nums[end - (i - start)] = t;
        }
    }

    public void nextPermutation(int[] nums) {
        if (nums == null || nums.length < 2) {
            return;
        }
        int len = nums.length;
        if (len == 2) {
            reverse(nums, 0, 1);
            return;
        }
        int t = 0;
        int pos = -1;
        for (int i = len - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            reverse(nums, 0, nums.length - 1);
            return;
        }
        for (int j = len - 1; j > pos; --j) {
            if (nums[j] > nums[pos]) {
                t = nums[j];
                nums[j] = nums[pos];
                nums[pos] = t;
                reverse(nums, pos + 1, len - 1);
                return;
            }
        }
    }
}
