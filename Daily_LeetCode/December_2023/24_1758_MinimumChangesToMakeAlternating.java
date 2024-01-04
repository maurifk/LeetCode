class Solution {
    public int minOperations(String s) {
        int empezarCero = 0;
	int empezarUno = 0;
	for (int i = 0; i<s.length(); ++i){
		if (i % 2 == 0) {
			if (s.charAt(i) == '0') {
				empezarUno++;
			} else {
				empezarCero++;
			}
		} else {
			if (s.charAt(i) == '1') {
				empezarUno++;
			} else {
				empezarCero++;
			}
		}
	}
	return empezarUno < empezarCero ? empezarUno : empezarCero;
    }
}
