import java.util.HashSet;
import java.util.Set;
import javafx.util.Pair;

class Solution {
	// Pair of (Pair of (Set of  previous points, current point)) and boolean to indicate if the path crossed
    private Pair<Pair<Set<Pair<Integer, Integer>>, Pair<Integer, Integer>>, Boolean> recorredor(Pair<Pair<Set<Pair<Integer, Integer>>, Pair<Integer, Integer>>, Boolean>  acc, char c) {
        if (acc.getValue()) {
            return new Pair<>(null, true);
        }
		if (acc.getKey().getKey().isEmpty()) {
			acc.getKey().getKey().add(new Pair<Integer,Integer>(0, 0));
		}

        int x = 0;
        int y = 0;
        switch (c) {
            case 'N':
                y = 1;
                break;
            case 'S':
                y = -1;
                break;
            case 'E':
                x = 1;
                break;
            case 'W':
                x = -1;
                break;
        }
        Pair<Integer, Integer> punto = new Pair<>(acc.getKey().getValue().getKey() + x, acc.getKey().getValue().getValue() + y);

        if (!acc.getKey().getKey().add(punto)) {
            return new Pair<>(null, true);
        }

        return new Pair<Pair<Set<Pair<Integer, Integer>>, Pair<Integer, Integer>>, Boolean>(new Pair<Set<Pair<Integer, Integer>>, Pair<Integer, Integer>>(acc.getKey().getKey(), punto), false);
    }

    public boolean isPathCrossing(String path) {
        return path.chars().mapToObj(i -> (char) i).reduce(
			new Pair<Pair<Set<Pair<Integer, Integer>>, Pair<Integer, Integer>>, Boolean>(
				new Pair<Set<Pair<Integer, Integer>>, Pair<Integer, Integer>>(new HashSet<Pair<Integer, Integer>>(), new Pair<>(0, 0)), false),
			(acc, c) -> recorredor(acc, c),
			(acc1, acc2) -> acc1
		).getValue();
    }
}
