import java.util.HashMap;
import java.util.Map;

class Solution {
    public int minSteps(String s, String t) {
        Map<Character, Integer> mapa1 = new HashMap<>();
        Map<Character, Integer> mapa2 = new HashMap<>();

        for (int i = 0; i<s.length(); ++i) {
            mapa1.put(s.charAt(i), mapa1.getOrDefault(s.charAt(i), 0) + 1);
            mapa2.put(t.charAt(i), mapa2.getOrDefault(t.charAt(i), 0) + 1);
        }

		int res = 0;
        for (Map.Entry<Character, Integer> letra : mapa1.entrySet()) {
			if (mapa2.getOrDefault(letra.getKey(), 0) < letra.getValue()) {
				res += letra.getValue() - mapa2.getOrDefault(letra.getKey(), 0);
			}
		}

		return res;
    }
}
