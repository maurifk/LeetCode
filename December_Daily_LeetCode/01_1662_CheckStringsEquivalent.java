package December_Daily_LeetCode;

import java.util.Arrays;

class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        /*
        String str1 = "";
        String str2 = "";

        str1 = Arrays.asList(word1).stream().reduce((acc, str) -> {
            return acc + str;
        }).get();

        str2 = Arrays.asList(word2).stream().reduce((acc, str) -> {
            return acc + str;
        }).get();

        return str1.equals(str2);
        */
        return Arrays.asList(word1).stream().reduce((acc, str) -> {
            return acc + str;
        }).get().equals(Arrays.asList(word2).stream().reduce((acc, str) -> {
            return acc + str;
        }).get());
    }
}