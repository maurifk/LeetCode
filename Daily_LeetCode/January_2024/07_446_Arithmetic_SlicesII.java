import java.util.HashMap;
import java.util.Map;

class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        Map<Long, Integer>[] dp = new HashMap[nums.length];
        for (int i = 0; i < nums.length; i++) {
            dp[i] = new HashMap<>();
        }

        int runningTotal = 0;
        for (int i = 1; i<nums.length; ++i) {
            for (int j = 0; j<i; ++j) {
                long diff = (long) nums[i] - (long) nums[j];
                int countJ = dp[j].getOrDefault(diff, 0);
                dp[i].put(diff, dp[i].getOrDefault(diff, 0) + countJ + 1);
                if (countJ > 0) {
                    runningTotal += countJ;
                }
            }
        }
        return runningTotal;
    }
}