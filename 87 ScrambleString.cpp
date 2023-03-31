#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  unordered_map<string, bool> mapa;

  bool isScramble(string s1, string s2) {
    int n = s1.size();
    if (s2.size() != n) return false;
    if (s1 == s2) return true;
    if (n == 1) return false;

    string clave = s1 + " " + s2;
    if(mapa.find(clave) != mapa.end()) return mapa[clave];

    for (int i = 1; i<n; ++i){
      bool noVuelta = (isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)));
      if (noVuelta) {
        mapa[clave] = true;
        return true;
      }

      bool siVuelta = (isScramble(s1.substr(0,i),s2.substr(n-i)) && isScramble(s1.substr(i),s2.substr(0,n-i)));
      if(siVuelta){
        mapa[clave] = true;
        return true;
      }
    }

    return mapa[clave] = false;
  }
};