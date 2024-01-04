import java.util.HashMap;

class Solution {
	// Ignored the fact it is sorted
    public int findSpecialInteger(int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i<arr.length; ++i) {
            if (!map.containsKey(arr[i])){
                if (arr.length == 1) return arr[i];
                map.put(arr[i], 1);
            } else {
                if (map.get(arr[i]) + 1 > arr.length / 4.0) return arr[i];
                map.put(arr[i], map.get(arr[i]) + 1);
            }
        }
        return -1;
    }
}
