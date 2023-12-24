import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {

	private Set<Long> distancias (int[] fences, int size) {
		Set<Long> res = new HashSet<>();
		Arrays.sort(fences);
		for (int i = 0; i<fences.length; ++i) {
			for (int j = i+1; j<fences.length; ++j) {
				res.add(Long.valueOf(fences[j] - fences[i]));
			}
		}

		for (int i = 0; i<fences.length; ++i) {
			res.add(Long.valueOf(size - fences[i]));
		}

		for (int i = 0; i<fences.length; ++i) {
			res.add(Long.valueOf(fences[i]-1));
		}

		res.add(Long.valueOf(size-1));

		return res;
	}

	public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
		Set<Long> hDistancias = distancias(hFences, m);
		Set<Long> vDistancias = distancias(vFences, n);
		hDistancias.retainAll(vDistancias);
		Long max = Long.valueOf(-1);
		for (Long i : hDistancias) {
			max = Math.max(max, i*i);
		}
		if (max == 0) {
			return -1;
		}
		return (int) (max % (1000000007));
	}
}
