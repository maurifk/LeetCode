package December_Daily_LeetCode;

import java.util.ArrayList;

class Solution {
    public String largestGoodInteger(String num) {
		if (num.length() == 0)
			return "";

		ArrayList<String> list = new ArrayList<String>();
		list.add(String.valueOf(num.charAt(0)));

		for (int i = 1; i<num.length(); ++i) {
			if (num.charAt(i-1) == num.charAt(i)) {
				list.set(list.size()-1, list.get(list.size()-1) + num.charAt(i));
			} else {
				list.add(String.valueOf(num.charAt(i)));
			}
		}

		String[] listaFiltr = list.stream().filter(str -> str.length() >= 3).sorted().toArray(String[]::new);

		return listaFiltr.length == 0 ? "" : listaFiltr[listaFiltr.length-1].substring(0, 3);
    }
}
