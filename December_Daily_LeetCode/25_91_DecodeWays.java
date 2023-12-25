class Solution {
    private boolean esNumeroDosDigitos(String s) {
		return s.charAt(0) == '1' || (s.charAt(0) == '2' && s.charAt(1) <= '6');
	}

	public int numDecodings(String s) {
		int[] dp = new int[s.length() + 1];
		dp[0] = 1;
		dp[1] = s.charAt(0) == '0' ? 0 : 1;
		for (int i = 2; i<=s.length(); i++) {
			if (s.charAt(i - 1) != '0') {
				dp[i] += dp[i - 1];
			}
			if (esNumeroDosDigitos(s.substring(i - 2, i))) {
				dp[i] += dp[i - 2];
			}
		}
		return dp[s.length()];
    }
}
