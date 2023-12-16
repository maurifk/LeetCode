class Solution {
    public boolean isAnagram(String s, String t) {
        if (t.length() != s.length()) return false;

        StringBuilder sBui = new StringBuilder(s);

        for (int i = 0; i < t.length(); ++i) {
            int ind = sBui.indexOf(t.charAt(i) + "");
            if (ind != -1) {
                sBui.setCharAt(ind, ' ');
            } else {
                return false;
            }
        }
        return true;
    }
}
