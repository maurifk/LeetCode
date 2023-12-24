import java.util.ArrayList;
import java.util.List;

class Solution {
  public List<String> helperGenerador(int n, String s, int abiertos) {
    if(s.length() != n*2) {
      if (s.length() + abiertos > n*2) { // Cant close them
        return new ArrayList<>();
      } else if (s.length() + abiertos == n*2) { // Cant open more
        StringBuilder sb = new StringBuilder(s);
        sb.append(')');
        return helperGenerador(n, sb.toString(), abiertos-1);
      } else if (abiertos > 0){ // Can do both
        StringBuilder sb1 = new StringBuilder(s);
        StringBuilder sb2 = new StringBuilder(s);
        sb1.append('(');
        sb2.append(')');
        List<String> izq = helperGenerador(n, sb1.toString(), abiertos+1);
        List<String> der = helperGenerador(n, sb2.toString(), abiertos-1);
        izq.addAll(der);
        return izq;
      } else { // Cant close any
        StringBuilder sb = new StringBuilder(s);
        sb.append('(');
        return helperGenerador(n, sb.toString(), abiertos+1);
      }
    } else {
      List<String> res = new ArrayList<>();
      res.add(s);
      return res;
    }
  }
  public List<String> generateParenthesis(int n) {
    return helperGenerador(n, "(", 1);
  }
}
