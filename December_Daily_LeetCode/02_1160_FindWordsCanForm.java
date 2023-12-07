import java.util.Arrays;

class Solution {
    public Boolean puedeFormarse(String palabra, String letras) {
        if (palabra.length() > letras.length())
            return false;

        char arrTemp[] = palabra.toCharArray();
        Arrays.sort(arrTemp);
        String palSorteada = new String(arrTemp);

        Integer puntLetras = 0;
        for(int i = 0; i<palSorteada.length(); ++i){
            char c = palSorteada.charAt(i);
            while (puntLetras < letras.length() && c != letras.charAt(puntLetras)) {
                puntLetras++;
            }
            if (puntLetras < letras.length()) {
                puntLetras++;
                continue;
            } else {
                return false;
            }

        }
        return true;
    }

    public int countCharacters(String[] words, String chars) {
        char arrTemp[] = chars.toCharArray();
        Arrays.sort(arrTemp);
        String letrasSorteadas = new String(arrTemp);

        int res = 0;
        for (String pal : words){
            if (puedeFormarse(pal, letrasSorteadas))
                res += pal.length();
        }

        return res;
    }
}
