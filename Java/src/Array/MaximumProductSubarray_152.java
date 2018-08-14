package Array;

public class MaximumProductSubarray_152 {
    public int maxProduct(int[] nums) {
        if (nums == null || nums.length < 1) {
            return 0;
        }
        int n = nums.length;
        int min;
        int max;
        int ans = max = min = nums[0];

        for (int i = 1; i < n; ++i) {
            int maxProv = max * nums[i];
            int minProv = min * nums[i];
            min = Math.min(nums[i], Math.min(minProv, maxProv));
            max = Math.max(nums[i], Math.max(minProv, maxProv));
            ans = Math.max(ans, max);
        }

        return ans;

    }
//    public int maxProduct(int[] nums) {
//        if (nums == null || nums.length < 1) {
//            return 0;
//        }
//        int n = nums.length;
//        int ans = 0;
//        int sub = 0;
//        for (int i = 0; i < n; ++i) {
//            sub = nums[i];
//            if ( i == 0) {
//                ans = sub;
//            } else if (sub > ans) {
//                ans = sub;
//            }
//            for (int j = i + 1; j < n; ++j) {
//                sub *= nums[j];
//                if (sub > ans) {
//                    ans = sub;
//                }
//            }
//        }
//        return ans;
//    }
}
