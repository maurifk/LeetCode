import java.util.ArrayList;
import java.util.List;

class Solution {
    int limitGlobal = -1;
    long globalRes = 0;
    long suffixL = -1;
    long startG = 0;
    long finishG = 0;
    int digsSuffG = 0;

    private void recursiveFors(List<Integer> currentCombination, int remainingDigits) {
        if (remainingDigits == 0) {
            long number = suffixL;
            for (int i = 0; i<currentCombination.size(); ++i) {
                number += currentCombination.get(i) * (Math.pow(10, currentCombination.size() - 1 - i + digsSuffG - 1));
            }
            if (number >= startG && number <= finishG) {
                System.out.println(number);
                globalRes++;
            }
        } else {
            for (int i = 0; i <= limitGlobal; i++) {
                List<Integer> newCombination = new ArrayList<>(currentCombination);
                newCombination.add(i);
                recursiveFors(newCombination, remainingDigits - 1);
            }
        }
    }

    public long numberOfPowerfulInt(long start, long finish, int limit, String s) {
        suffixL = Long.parseLong(s);
        limitGlobal = limit;
        startG = start;
        finishG = finish;
        int digsSufx = s.length();
        digsSuffG = digsSufx;
        int digs = (int) Math.ceil(Math.log10(finish));

        if (digsSufx > digs || suffixL > finish || suffixL < start) return 0;
        recursiveFors(new ArrayList<>(), digs - digsSufx);

        return globalRes;
    }
}
