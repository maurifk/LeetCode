import java.util.Arrays;

import javafx.util.Pair;

class Solution {
    public Pair<Integer, Integer> maxDiff(Pair<Integer, Integer> acc, int n) {
        if (acc.getValue() == -1)
            return new Pair<>(0, n);

        if (n - acc.getValue() > acc.getKey()) {
            return new Pair<>(n - acc.getValue(), n);
        } else {
            return new Pair<>(acc.getKey(), n);
        }
    }

    public int maxWidthOfVerticalArea(int[][] points) {
        return Arrays.stream(points).map(x -> x[0]).sorted().reduce(
            new Pair<>(0,-1),
            (acc, i) -> maxDiff(acc, i),
            (acc1, acc2) -> acc1
        ).getKey();
    }
}
