import java.util.Arrays;

import javafx.util.Pair;

class Solution {
    public Pair<Integer, Integer> dosMayores(Pair<Integer, Integer> previos, int compt) {
        if (previos.getValue() > compt) return previos;

        if (previos.getKey() > compt) return new Pair<Integer, Integer>(previos.getKey(), compt);

        return new Pair<Integer, Integer>(compt, previos.getKey());
    }

    public int maxProduct(int[] nums) {
        Pair<Integer, Integer> par = Arrays.stream(nums).boxed().reduce(
            new Pair<>(-1, -1),
            (acc, i) -> dosMayores(acc, i),
            (acc1, acc2) -> acc1
        );
        return (par.getKey() - 1) * (par.getValue() - 1);
    }
}
