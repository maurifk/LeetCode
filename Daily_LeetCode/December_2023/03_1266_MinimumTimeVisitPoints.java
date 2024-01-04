import java.util.Arrays;
import javafx.util.Pair;

class Solution {

    public int abs(int i){
        return (i<0) ? -i : i;
    }

    public int max(int i, int j){
        return (i>j) ? i : j;
    }

    public int distanciaEspecial(int[] a, int[] b){
        return max(abs(a[0] - b[0]), abs(a[1] - b[1]));
    }

    public int minTimeToVisitAllPoints(int[][] points) {
        return Arrays.asList(points).stream().reduce(
            new Pair<>(points[0], 0),
            (Pair<int[], Integer> acc, int[] x) -> {
                return new Pair<>(x, acc.getValue() + distanciaEspecial(x, acc.getKey()));
            },
            (acc1, acc2) -> acc2 // Necesaria por si fuera a paralelizar !!
        ).getValue();
    }
}