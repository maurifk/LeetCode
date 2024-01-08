class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        double maxDiag = 0;
        int maxArea = 0;
        for (int[] rect : dimensions) {
            double diag = Math.sqrt(Math.pow(rect[0], 2) + Math.pow(rect[1], 2));
            int area = rect[0] * rect[1];
            if (diag > maxDiag) {
                maxDiag = diag;
                maxArea = area;
            } else if (diag == maxDiag) {
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
        return maxArea;
    }
}