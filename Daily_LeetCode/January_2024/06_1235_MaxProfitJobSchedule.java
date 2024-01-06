import javafx.util.Pair;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

// Works but TLE since dp array can be too big
/*
class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        List<Pair<Pair<Integer, Integer>, Integer>> jobs = new ArrayList<>();
        int maxET = 0;
        int maxST = 0;
        for (int i = 0; i < startTime.length; i++) {
            jobs.add(new Pair<>(new Pair<>(startTime[i], endTime[i]), profit[i]));

            if (startTime[i] > maxST)
                maxST = startTime[i];

            if (endTime[i] > maxET) 
                maxET = endTime[i];
        }
        jobs.sort((a, b) -> a.getKey().getKey() - b.getKey().getKey());

        int lastJobChecked = jobs.size()-1;
        int[] dp = new int[maxST+1];

        for (int i = maxST; i>=1; --i) {
            int maxProfit = 0;
            while (lastJobChecked >= 0 && jobs.get(lastJobChecked).getKey().getKey() == i) {
                Pair<Pair<Integer, Integer>, Integer> job = jobs.get(lastJobChecked);
                int jobET = job.getKey().getValue();
                maxProfit = Math.max(maxProfit, job.getValue() + jobET <= maxST ? dp[job.getKey().getValue()] : 0);
                --lastJobChecked;
            }

            if (i<maxET) {
                maxProfit = Math.max(maxProfit, dp[i+1]);
            }

            dp[i] = maxProfit;
        }

        return dp[1];
    }
}
*/
class Solution {
    private int lowerBound(List<Pair<Pair<Integer, Integer>, Integer>> list, int key) {
        int index = Collections.binarySearch(list, 
                                             new Pair<>(new Pair<>(key, 0), 0),
                                             (a, b) -> a.getKey().getKey().compareTo(b.getKey().getKey()));

        if (index < 0)
            return -index - 1;

        while (index > 0) {
            if (list.get(index - 1).getKey().getKey() == key) {
                --index;
            } else {
                return index;
            } 
        }

        return index;
    }

        public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        List<Pair<Pair<Integer, Integer>, Integer>> jobs = new ArrayList<>();
        for (int i = 0; i < startTime.length; i++) {
            jobs.add(new Pair<>(new Pair<>(startTime[i], endTime[i]), profit[i]));
        }
        jobs.sort((a, b) -> a.getKey().getKey() - b.getKey().getKey());

        int[] dp = new int[jobs.size()];

        for (int i = jobs.size()-1; i>=0; --i) {
            int index = lowerBound(jobs, jobs.get(i).getKey().getValue());

            if (index != jobs.size()) {
                dp[i] = Math.max(jobs.get(i).getValue() + dp[index], dp[i + 1]);
            } else {
                if (i < jobs.size() - 1) {
                    dp[i] = Math.max(jobs.get(i).getValue(), dp[i + 1]);
                } else {
                    dp[i] = jobs.get(i).getValue();
                }
            }
        }

        return dp[0];
    }
}