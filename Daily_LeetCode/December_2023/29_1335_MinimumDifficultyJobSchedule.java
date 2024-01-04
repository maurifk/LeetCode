class Solution {
    public int minDifficulty(int[] jobDifficulty, int d) {
        if (jobDifficulty.length < d) {
            return -1;
        }
        int length = jobDifficulty.length;
        int sum = 0;

        for (int i = 0; i<length; ++i) {
            sum += jobDifficulty[i];
        }

        if (sum == 0) {
            return 0;
        }

        int[][] dp = new int[d+1][length];
        dpCalculador(jobDifficulty, d, 0, dp);

        return dp[d][0];
    }

    private void dpCalculador(int[] jobs, int d, int ind, int[][] dp) {
        if (dp[d][ind] != 0) {
            return;
        }

        if (d == 1) {
            int sum = 0;
            for (int i = ind; i<jobs.length; ++i) {
                sum = Math.max(sum, jobs[i]);
            }
            dp[d][ind] = sum;
            return;
        }

        int maxDias = jobs[ind];
        d--;
        int fin = jobs.length - ind - d + 1;
        int minRes = Integer.MAX_VALUE;
        for (int i = 1; i<fin; ++i) {
            maxDias = Math.max(maxDias, jobs[ind + i - 1]);
            int resto = dp[d][ind + i];
            if (resto == 0) {
                dpCalculador(jobs, d, ind + i, dp);
                resto = dp[d][ind + i];
            }
            minRes = Math.min(minRes, resto + maxDias);
        }
        dp[d+1][ind] = minRes;
    }
}