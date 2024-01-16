import java.util.PriorityQueue;
import java.util.Queue;

class Solution {
    public boolean closeStrings(String word1, String word2) {
        if (word1.length() != word2.length()) return false;

        int[] mapa1 = new int[26];
        int[] mapa2 = new int[26];

        for (int i = 0; i<word1.length(); ++i) {
            mapa1[word1.charAt(i)-'a']++;
            mapa2[word2.charAt(i)-'a']++;

        }

        Queue<Integer> lista1 = new PriorityQueue<>();
        Queue<Integer> lista2 = new PriorityQueue<>();
        for (int i = 0; i<26; ++i) {
            if (mapa1[i] == mapa2[i]) continue;
            if (mapa1[i] == 0 || mapa2[i] == 0) return false;

            lista1.add(mapa1[i]);
            lista2.add(mapa2[i]);
        }

        while (!lista1.isEmpty()) {
			int l1 = lista1.poll();
			int l2 = lista2.poll();

			if (l1 != l2) return false;
        }

        return true;
    }
}
