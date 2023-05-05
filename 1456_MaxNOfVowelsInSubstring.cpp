#include <string>
using namespace std;

class Solution {
public:
  int maxVowels(string s, int k) {
    int izq = 0, der = 0;
    int maxi = 0;
    int cont = 0;
    while (der < s.length()) {
      if (der - izq < k) {
        if (s[der] == 'a' || s[der] == 'e' || s[der] == 'i' || s[der] == 'o' || s[der] == 'u') {
          cont++;
        }
        der++;
        maxi = max(maxi, cont);
      } else {
        if (s[izq] == 'a' || s[izq] == 'e' || s[izq] == 'i' || s[izq] == 'o' || s[izq] == 'u') {
          cont--;
        }
        if (s[der] == 'a' || s[der] == 'e' || s[der] == 'i' || s[der] == 'o' || s[der] == 'u') {
          cont++;
        }
        izq++;
        der++;
        maxi = max(maxi, cont);
      }
    }
    return maxi;
  }
};
