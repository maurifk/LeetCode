import java.util.List;
import java.util.Set;
import java.util.ArrayList;
import java.util.HashSet;

class Solution {
	public List<List<Integer>> findMatrix(int[] nums) {
		List<Set<Integer>> tempRes = new ArrayList<>();
		List<List<Integer>> res = new ArrayList<>();

		for (int i : nums) {
			boolean agregado = false;
			int j = 0;

			do {
				if (j >= tempRes.size()) {
					tempRes.add(new HashSet<>());
					tempRes.get(j).add(i);
					agregado = true;

				} else {
					if (tempRes.get(j).contains(i)) {
						++j;
					} else {
						tempRes.get(j).add(i);
						agregado = true;
					}
				}
			} while (!agregado);
		}

		for (Set<Integer> set : tempRes) {
			res.add(new ArrayList<>(set));
		}

		return res;
	}
}
