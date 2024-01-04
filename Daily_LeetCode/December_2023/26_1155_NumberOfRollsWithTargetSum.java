class Solution {
    public int numRollsToTarget(int n, int k, int target) {
		long [][] dp = new long [n+1][target+1];
		for (int i = 1; i<=target; ++i) {
			dp[1][i] = i<=k ? 1 : 0;
		}

		for (int i = 2; i<=n; ++i){ // For each dice, bottom up
			for (int targ = 1; targ <= target; ++targ) {
				long sum = 0;
				for (int j = 1; j<=k && targ - j > 0; ++j) { // Try every face in ith dice
					sum += dp[i-1][targ - j] % (1000000007);
				}
				dp[i][targ] = sum;
			}
		}

		return (int) (dp[n][target] % (1000000007));
    }
}
