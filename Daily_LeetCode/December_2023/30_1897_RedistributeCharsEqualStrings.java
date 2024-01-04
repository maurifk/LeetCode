import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean makeEqual(String[] words) {
        Map<Character, Integer> mapa = new HashMap<>();
        for (int i = 0; i<words.length; ++i) {
            for (int j = 0; j<words[i].length(); ++j) {
                mapa.put(words[i].charAt(j), mapa.getOrDefault(words[i].charAt(j), 0) + 1);
            }
        }
        
        for (Integer cant : mapa.values()) {
            if (cant % words.length != 0)
                return false;
        }

        return true;
    }
}