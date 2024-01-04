import java.util.Arrays;

class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);

        int res = 0;
        int puntG = g.length - 1;
        int puntS = s.length - 1;

        while (puntS >= 0 && puntG >= 0) {
            if (g[puntG] > s[puntS]) {
                puntG--;
            } else {
                puntG--;
                puntS--;
                res++;
            }
        }
        return res;
    }
}