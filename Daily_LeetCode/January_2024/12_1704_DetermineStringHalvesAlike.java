class Solution {
    private boolean esVocal(char c) {
        c = Character.toLowerCase(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    public boolean halvesAreAlike(String s) {
        String s1 = s.substring(0, s.length()/2);
        String s2 = s.substring(s.length()/2);
        int i1 = 0, i2 = 0;
        for (int i = 0; i<s1.length(); ++i) {
            if (esVocal(s1.charAt(i))) i1++;
            if (esVocal(s2.charAt(i))) i2++;
        }

        return i1 == i2;
    }
}
