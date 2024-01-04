class Solution {
    boolean estaAdentro(int m, int n, int x, int y) {
        return (0 <= x) && (x < m) && (0 <= y) && (y < n);
    }
    public int[][] imageSmoother(int[][] img) {
        int m = img.length;
        int n = img[0].length;
        int[][] res = new int[m][n];
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y <n; ++y) {
                int cont = 0;
                int sum = 0;
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        if (!estaAdentro(m, n, x+i, y+j)) continue;
                        cont++;
                        sum += img[x+i][y+j];
                    }
                }
                res[x][y] = sum / cont;
            }
        }
        return res;
    }
}
