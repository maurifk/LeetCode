import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import javafx.util.Pair;

class Solution {
	private Map<Pair<Character, Character>, Integer> map = new HashMap<>();
	private List<List<Pair<Integer, Integer>>> list = new ArrayList<>(26);

	public int costMemoizado(char origen, char destino) {
		if (origen == destino) {
			return 0;
		}

		Pair<Character, Character> pair = new Pair<>(origen, destino);
		if (map.containsKey(pair)) {
			return map.get(pair);
		}
		int cost = cost(origen, destino);
		map.put(pair, cost);
		return cost;
	}

	public int cost(char origen, char destino) {
		boolean[] visited = new boolean[26];
		for (int i = 0; i<26; i++) {
			visited[i] = false;
		}

		PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>((a, b) -> a.getValue() - b.getValue());
		pq.add(new Pair<>(origen - 'a', 0));

		while (!pq.isEmpty()) {
			Pair<Integer, Integer> pair = pq.poll();
			int u = pair.getKey();
			char c = (char) (u + 'a');
            if (visited[u]) {
                continue;
            }
			map.put(new Pair<>(origen, c), pair.getValue());

			visited[u] = true;
			if (u == destino - 'a') {
				return pair.getValue();
			}

			for (Pair<Integer, Integer> p : list.get(u)) {
				int v = p.getKey();
				if (!visited[v]) {
					pq.add(new Pair<>(v, pair.getValue() + p.getValue()));
				}
			}
		}

		return -1;
	}

    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
		for (int i = 0; i<26; i++) {
			list.add(i, new ArrayList<>());
		}

		for (int i = 0; i<original.length; i++) {
			list.get(original[i] - 'a').add(new Pair<>(changed[i] - 'a', cost[i]));
		}

		long sum = 0;

		for (int i = 0; i<source.length(); i++) {
			int costo = costMemoizado(source.charAt(i), target.charAt(i));
			if (costo == -1) {
				return -1;
			}
			sum += costo;
		}

		return sum;
    }

	public static void main(String[] args) {
		Solution sol = new Solution();
		String source = "aacbbabdad";
		String target = "ddadcababd";
		char[] original = {'d','b','c','a','b','c','d','c','b','a','a'};
		char[] changed = {'c','d','d','b','c','b','b','a','a','c','d'};
		int[] cost = {7,10,4,2,7,4,4,4,6,2,8};
		System.out.println(sol.minimumCost(source, target, original, changed, cost));
	}
}
