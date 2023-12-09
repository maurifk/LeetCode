package Java_LeetCode;

class Solution {
    public int minimumRecolors(String blocks, int k) {
        int cantW = 0;

        for (int i = 0; i < k; ++i) {
            if (blocks.charAt(i) == 'W') {
                cantW++;
            }
        }
        
        int minR = cantW;
        
        for (int i = k; i<blocks.length(); ++i) {
            if (blocks.charAt(i-k) != blocks.charAt(i)) {
                if (blocks.charAt(i) == 'W') {
                    ++cantW;
                } else {
                    --cantW;
                }
                minR = minR - cantW > 0 ? cantW : minR; 
            }
        }

        return minR;
    }
}