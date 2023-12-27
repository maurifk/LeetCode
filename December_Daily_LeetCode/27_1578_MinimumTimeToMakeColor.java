class Solution {
    public int minCost(String colors, int[] neededTime) {
		char c = ' ';
		int sum = 0;
		int localSum = 0;
		int localMax = -1;
		for (int i = 0; i<colors.length(); ++i) {
			if (c == colors.charAt(i)) {
				localMax = localMax < neededTime[i] ? neededTime[i] : localMax;
				localSum += neededTime[i];
			} else {
				if (i != 0) {
					sum += localSum - localMax;
				}

				localMax = neededTime[i];
				localSum = neededTime[i];
				c = colors.charAt(i);
			}
		}

		if (colors.length() != 1) {
			sum += localSum - localMax;
		}

		return sum;
    }
}
