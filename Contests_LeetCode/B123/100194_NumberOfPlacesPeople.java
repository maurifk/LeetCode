class Solution {
	private int[][] nums;

	private boolean validFence (int x1, int y1, int x2, int y2){
		return (x1 <= x2 && y1 >= y2);
	}

	private boolean willBeSad(int p1, int p2) {
		int x1 = nums[p1][0], y1 = nums[p1][1], x2 = nums[p2][0], y2 =  nums[p2][1];
		for (int i = 0; i<nums.length; ++i)
			if (i != p1 && i != p2)
				if (x1<=nums[i][0] && y1>=nums[i][1] && nums[i][0]<=x2 && nums[i][1]>=y2)
					return true;

		return false;
	}

    public int numberOfPairs(int[][] points) {
		nums = points;

		int res = 0;
		for (int i = 0; i<points.length-1; ++i) {
			for (int j = i+1; j<points.length; ++j) {
				if (validFence(points[i][0], points[i][1], points[j][0], points[j][1]) && !willBeSad(i, j)) {
					++res;
				}
			}
		}
		for (int j = 0; j<points.length-1; ++j) {
			for (int i = j+1; i<points.length; ++i) {
				if (validFence(points[i][0], points[i][1], points[j][0], points[j][1]) && !willBeSad(i, j)) {
					++res;
				}
			}
		}
		return res;
    }
}
