class Solution {
    public int majorityElement(int[] nums) {
		int majority = 0;
		int i = 0;
		for (int n : nums) {
			if (i == 0) {
				majority = n;
				i++;
			} else if (majority == n) {
				i++;
			} else {
				i--;
			}
		}
		return majority;
    }
}
