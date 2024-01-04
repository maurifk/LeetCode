import java.util.HashMap;

class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
		HashMap<Integer, Integer> mapOnesRow = new HashMap<>();
		HashMap<Integer, Integer> mapZerosRow = new HashMap<>();
		HashMap<Integer, Integer> mapOnesCol = new HashMap<>();
		HashMap<Integer, Integer> mapZerosCol = new HashMap<>();
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++) {
				if (grid[i][j] == 1) {
					mapOnesRow.put(i, mapOnesRow.getOrDefault(i, 0) + 1);
					mapOnesCol.put(j, mapOnesCol.getOrDefault(j, 0) + 1);
				} else {
					mapZerosRow.put(i, mapZerosRow.getOrDefault(i, 0) + 1);
					mapZerosCol.put(j, mapZerosCol.getOrDefault(j, 0) + 1);
				}
			}
		}

		int[][] res = new int[grid.length][grid[0].length];
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++) {
				res[i][j] = mapOnesCol.getOrDefault(j, 0) + mapOnesRow.getOrDefault(i, 0) - mapZerosCol.getOrDefault(j, 0) - mapZerosRow.getOrDefault(i, 0);
			}
		}

		return res;
    }
}
