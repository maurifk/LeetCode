class Solution {
    private boolean cBetweenAandB(int a, int b, int c) {
        if (a > b) {
            return a > c && c > b;
        } else {
            return b > c && c > a;
        }
    }

    public int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        boolean rookQueenAligned = a == e || b == f;
        boolean bishopQueenAligned = Math.abs(c - e) == Math.abs(d - f);

        if (!rookQueenAligned && !bishopQueenAligned)
            return 2;

        if (rookQueenAligned && bishopQueenAligned)
            return 1;

        if (rookQueenAligned) {
            if (a == e) {
                if (c != a) 
                    return 1;

                return cBetweenAandB(b, f, d) ? 2 : 1;
            } else {
                if (d != b) 
                    return 1;

                return cBetweenAandB(a, e, c) ? 2 : 1;
            }
        } else {
            if (Math.abs(a - c) == Math.abs(b - d) && Math.abs(a - e) == Math.abs(b - f)) {
                return cBetweenAandB(c, e, a) ? 2 : 1;
            } else {
                return 1;
            }
        }
    }
}