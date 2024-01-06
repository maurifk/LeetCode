import java.util.HashSet;
import java.util.Set;

class Solution {
    public int missingInteger(int[] nums) {
        Set<Integer> set = new HashSet<>();
        int sum = 0;
        boolean stillPrefix = true;

        for (int i = 0; i<nums.length; ++i) {
            if (i != 0) {
                if (stillPrefix) {
                    if (nums[i] == nums[i-1] + 1) {
                        sum += nums[i];
                    } else {
                        stillPrefix = false;
                    }
                }
            } else {
                sum = nums[i];
            }
            set.add(nums[i]);
        }

        while (set.contains(sum)) {
            ++sum;
        }

        return sum;
    }
}
