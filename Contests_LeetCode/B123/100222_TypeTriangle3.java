class Solution {
	private boolean esTriangulo (int[] nums) {
		int i = nums[0] > nums[1] ? (nums[0] > nums[2] ? 0 : 2) : (nums[1] > nums[2] ? 1 : 2);

		int min = nums[i];
		int sum = 0;
		for (int j = 0; j<3; ++j) {
			if (j != i) {
				sum += nums[j];
			}
		}
		return sum > min;
	}

    public String triangleType(int[] nums) {
		if (!esTriangulo(nums)) return "none";

		if (nums[0] == nums[1] && nums[1] == nums[2]) {
			return "equilateral";
		} else if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) {
			return "isosceles";
		} else {
			return "scalene";
		}
    }
}
