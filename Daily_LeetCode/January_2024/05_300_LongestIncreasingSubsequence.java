class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        int globalMax = 0;
        for (int i = nums.length -1; i >= 0; --i) {
            int max = 0;
            for (int j = i+1; j<nums.length; ++j){
                if (nums[j] > nums[i] && dp[j] > max) {
                    max = dp[j];
                }
            }
            dp[i] = max + 1;
            if (dp[i] > globalMax)
                globalMax = dp[i];
        }
        return globalMax;
    }
}
