import java.util.Arrays;
import javafx.util.Pair;

class Solution {
    public Pair<Integer, Integer> dosMenores(Pair<Integer, Integer> previos, int compt) {
        if (previos.getValue() < compt) return previos;

        if (previos.getKey() < compt) return new Pair<Integer, Integer>(previos.getKey(), compt);

        return new Pair<Integer, Integer>(compt, previos.getKey());
    }

    public int buyChoco(int[] prices, int money) {
        Pair<Integer, Integer> par = Arrays.stream(prices).boxed().reduce(
            new Pair<>(101, 101),
            (acc, i) -> dosMenores(acc, i),
            (acc1, acc2) -> acc1
        );
        return money >= par.getKey() + par.getValue() ? money - par.getKey() - par.getValue() : money;
    }
}
