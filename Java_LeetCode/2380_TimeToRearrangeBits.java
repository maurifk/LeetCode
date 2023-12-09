package Java_LeetCode;

class Solution {
    public boolean tiene01 (StringBuilder s) {
        for (int i = 1; i<s.length(); ++i)
            if (s.charAt(i-1) == '0' && s.charAt(i) == '1')
                return true;
        
        return false;
    }

    public StringBuilder cambiar01por10 (StringBuilder s) {
        StringBuilder sRes = new StringBuilder(s);

        for (int i = 1; i< s.length(); ++i) {
            if (s.charAt(i-1) == '0' && s.charAt(i) == '1') {
                sRes.setCharAt(i-1, '1');
                sRes.setCharAt(i, '0');
            }
        }
        return sRes;
    }

    public int secondsToRemoveOccurrences(String s) {
        int seconds = 0;
        StringBuilder sAct = new StringBuilder(s);

        while (true) {
            if (!tiene01(sAct)) 
                break;
            
            sAct = cambiar01por10(sAct);
            ++seconds;
        }

        return seconds;
    }
}
