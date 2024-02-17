//You are given an array nums of length n and a positive integer k.
//A subarray of nums is called good if the absolute difference between its first and last element is exactly k, in other words, the subarray nums[i..j] is good if |nums[i] - nums[j]| == k.
//Return the maximum sum of a good subarray of nums. If there are no good subarrays, return 0.

import java.util.HashMap;

class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        long res = -1111111111111111L;
        boolean encontrado = false;
        long[] prefix = new long[nums.length + 1];
        for (int i = 1; i <= nums.length; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int j = 0; j < nums.length; ++j) {
            if (map.containsKey(nums[j])) {
                int i = map.get(nums[j]);
                encontrado = true;
                long sum = prefix[j + 1] - prefix[i];
                res = Math.max(res, sum);
            } else {
                map.put(k - nums[j], j);
                map.put(k + nums[j], j);
            }
        }
        return encontrado ? res : 0;
    }
}

