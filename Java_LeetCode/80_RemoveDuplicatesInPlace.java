class Solution {
    public int removeDuplicates(int[] nums) {
       int i = 0;
	   	for (int n = 0; n<nums.length; ++n) {
			if (i < 2 || nums[n] > nums[i - 2])
				nums[i++] = nums[n];
        }

		return i;
    }
}
