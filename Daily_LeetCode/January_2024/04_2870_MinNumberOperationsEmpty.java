import java.util.HashMap;
import java.util.Map;

class Solution {
	private int operationsForNumber(int n) {
		if (n == 1) {
			return -1;
		} else if (n <= 3) {
			return 1;
		} else {
			switch (n % 3) {
				case 0:
					return n / 3;
				case 1:
				case 2:
					return n / 3 + 1;
			}
		}
		return -1;
	}

    public int minOperations(int[] nums) {
		Map<Integer, Integer> mapa = new HashMap<>();
		for (int n : nums) {
			mapa.put(n, mapa.getOrDefault(n, 0) + 1);
		}

		int res = 0;
		for (Integer entry : mapa.values()) {
			int ops = operationsForNumber(entry);
			if (ops == -1) return -1;

			res += ops;
		}
		return res;
    }
}
