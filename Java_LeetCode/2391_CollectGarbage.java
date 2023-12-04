package Java_LeetCode;

class Solution {
    public int max(int i, int j, int k) {
        return (i > j) ? ((i > k) ? i : k) : (j > k ? j : k);
    }

    public int garbageCollection(String[] garbage, int[] travel) {
        int ultCasaP = -1;
        int ultCasaG = -1;
        int ultCasaM = -1;
        int encontrados = 0;

        for (int i = garbage.length - 1; i >= 0; --i){
            if (ultCasaG == -1) {
                if (garbage[i].contains("G")) {
                    ultCasaG = i;
                    encontrados++;
                }
            }

            if (ultCasaM == -1) {
                if (garbage[i].contains("M")) {
                    ultCasaM = i;
                    encontrados++;
                }
            }

            if (ultCasaP == -1) {
                if (garbage[i].contains("P")) {
                    ultCasaP = i;
                    encontrados++;
                }
            }

            if (encontrados == 3)
                break;
        }

        int tiempo = 0;

        for (int i = 0; i < max(ultCasaG, ultCasaM, ultCasaP); ++i) {
            if (i < ultCasaG) {
                tiempo += travel[i];
            }

            if (i < ultCasaP) {
                tiempo += travel[i];
            } 

            if (i < ultCasaM) {
                tiempo += travel[i];
            }
            tiempo += garbage[i].length();
        }
        
        tiempo += garbage[garbage.length-1].length();

        return tiempo;
    }
}
