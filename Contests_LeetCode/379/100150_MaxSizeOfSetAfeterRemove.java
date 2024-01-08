import java.util.*;

class Solution {
    public int maximumSetSize(int[] nums1, int[] nums2) {
        int n = nums1.length;
        Map<Integer, Integer> count1 = new HashMap<>();
        Map<Integer, Integer> count2 = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            count1.put(nums1[i], count1.getOrDefault(nums1[i], 0) + 1);
            count2.put(nums2[i], count2.getOrDefault(nums2[i], 0) + 1);
        }
        
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> (count1.getOrDefault(b, 0) + count2.getOrDefault(b, 0)) - (count1.getOrDefault(a, 0) + count2.getOrDefault(a, 0)));
        pq.addAll(count1.keySet());
        pq.addAll(count2.keySet());
        
        int countRemoved1 = 0, countRemoved2 = 0;
        while (!pq.isEmpty() && (countRemoved1 < n / 2 || countRemoved2 < n / 2)) {
            int num = pq.poll();
            if (count1.getOrDefault(num, 0) > count2.getOrDefault(num, 0) && countRemoved1 < n / 2) {
                count1.put(num, count1.get(num) - 1);
                countRemoved1++;
                if (count1.get(num) == 0) {
                    count1.remove(num);
                }
            } else if (count2.containsKey(num) && countRemoved2 < n / 2) {
                count2.put(num, count2.get(num) - 1);
                countRemoved2++;
                if (count2.get(num) == 0) {
                    count2.remove(num);
                }
            }
        }
        
        return count1.size() + count2.size();
    }
}