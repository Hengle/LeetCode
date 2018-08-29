package Array;

import java.util.ArrayList;

public class MaximumSumof3NonOverlappingSubarrays_689 {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        if (nums == null || nums.length < 3 * k) {
            return null;
        }
        int [] ans = new int[3];
        int minV = Integer.MIN_VALUE;
        int len = nums.length;
        int [] sum = new int[len + 1];
        for (int i = 0; i < len; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }

        int [] left = new int[len + 1];
        int total = sum[k];
        for (int i = k; i < len; ++i) {
            if (sum[i + 1] - sum[i + 1- k] > total) {
                left[i] = i + 1 - k;
                total = sum[i + 1] - sum[i+1-k];
            } else {
                left[i] = left[i - 1];
            }
        }
        int [] right = new int[len + 1];
        for (int i = right.length - 1; i >= 0; i--) {
            right[i] = len - k;
        }
        total = sum[len] - sum[len - k];
        for (int i = len - 1 - k; i >= 0; --i) {
            if (sum[i + k] - sum[i] >= total) {
                right[i] = i;
                total = sum[i + k] - sum[i];
            } else {
                right[i] = right[i + 1];
            }
        }
        for (int i = k; i <= len-2*k; ++i) {
            int l = left[i -1], r = right[i + k];
            total = sum[i + k] - sum[i] + sum[l + k] - sum[l] + sum[r + k] -  sum[r];
            if (minV < total) {
                minV = total;
                ans[0] = l;
                ans[1] = i;
                ans[2] = r;
            }
        }
        return ans;
    }
}
