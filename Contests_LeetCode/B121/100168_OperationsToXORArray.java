class Solution {
    public int minOperations(int[] nums, int k) {
        int xorRes = 0;
        for (int num : nums) {
            xorRes ^= num;
        }
        
        xorRes ^= k;

        int distance = 0;
        while (xorRes != 0) {
            if (xorRes % 2 == 1) {
                ++distance;
            }
            xorRes>>=1;
        }
        return distance;
    }
}
