class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int[][] dp = new int[matrix.length][matrix[0].length];
		for (int j = 0; j<matrix[0].length; ++j) {
			dp[matrix.length-1][j] = matrix[matrix.length-1][j];
		}

		for (int i = matrix.length-2; i>=0; --i) {
			for (int j = 0; j<matrix[0].length; ++j) {
				int min = Integer.MAX_VALUE;
				if (j == 0) {
					min = Math.min(dp[i+1][j], dp[i+1][j+1]);
				} else if (j == matrix[0].length-1) {
					min = Math.min(dp[i+1][j-1], dp[i+1][j]);
				} else {
					min = Math.min(dp[i+1][j-1], Math.min(dp[i+1][j], dp[i+1][j+1]));
				}
				dp[i][j] = min + matrix[i][j];
			}
		}

		int res = Integer.MAX_VALUE;
		for (int i = 0; i<matrix[0].length; ++i) {
			res = Math.min(res, dp[0][i]);
		}
		return res;
    }
}
