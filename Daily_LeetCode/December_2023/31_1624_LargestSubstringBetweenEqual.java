import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        Map<Character, Integer> mapa = new HashMap<Character, Integer>();
        for (int i = 0; i<s.length(); ++i) {
            mapa.put(s.charAt(i), mapa.getOrDefault(s.charAt(i), 0) + 1);
        }
        int max = -1;
        for (int i = 0; i<s.length(); ++i) {
            int maxLetra = -1;
            if (mapa.get(s.charAt(i)) > 1) {
                for (int j = i + 1; j<s.length(); ++j) {
                    if (s.charAt(i) == s.charAt(j)) {
                        maxLetra = j - i - 1;
                    }
                }
            }
            max = max < maxLetra ? maxLetra : max;
        }
        return max;
    }
}