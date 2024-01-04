class Solution {
    public int maxScore(String s) {
        int cantUnos = 0;
        for (int i = 0; i<s.length(); ++i){
            if (s.charAt(i) == '1') {
                cantUnos++;
            }
        }
        int max = -1;
        int cantUnosHastaAhora = 0;
        for(int i = 0; i<s.length()-1; ++i) {
            if (s.charAt(i) == '1') {
                cantUnosHastaAhora++;
            }
            int sum = i + 1 - 2 * cantUnosHastaAhora + cantUnos;
            if (sum > max) {
                max = sum;
            }
        }
        return max;
    }
}
