import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        Set<Integer> noneL = new HashSet<>();
        Set<Integer> oneL = new HashSet<>();
        Set<Integer> manyL = new HashSet<>();
        for (int[] part : matches) {
            if (!oneL.contains(part[0]) && !manyL.contains(part[0])) {
                noneL.add(part[0]);
            }

            if (manyL.contains(part[1])) {
                continue;
			}

            if (oneL.contains(part[1])) {
                oneL.remove(part[1]);
                manyL.add(part[1]);
                continue;
            }

            if (noneL.contains(part[1])) {
                noneL.remove(part[1]);
			}

            oneL.add(part[1]);
        }

        List<Integer> none = new ArrayList<>(noneL);
        none.sort(null);
        List<Integer> one = new ArrayList<>(oneL);
        one.sort(null);

        List<List<Integer>> res = new ArrayList<>();
        res.add(none);
        res.add(one);
        return res;
    }
}
