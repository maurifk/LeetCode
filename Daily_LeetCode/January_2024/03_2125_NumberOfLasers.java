class Solution {
    public int numberOfBeams(String[] bank) {
		int previousLasers = 0;
		int sum = 0;

		for (int i = 0; i<bank.length; ++i) {
			int cantLasers = 0;
			for (int j = 0; j<bank[i].length(); ++j) {
				if (bank[i].charAt(j) != '0') {
					cantLasers++;
				}
			}

			if (cantLasers == 0) continue;

			sum += previousLasers * cantLasers;

			previousLasers = cantLasers;
		}

		return sum;
    }
}
