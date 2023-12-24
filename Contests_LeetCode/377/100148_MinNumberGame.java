import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public int[] numberGame(int[] nums) {
        Arrays.sort(nums);
		ArrayList<Integer> res = new ArrayList<>();
		for (int i = 0; i<nums.length/2; ++i) {
			res.add(nums[i*2+1]);
			res.add(nums[i*2]);
		}
		return res.stream().mapToInt(i -> i).toArray();
    }
}
