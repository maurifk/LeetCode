#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  bool checkDistances(string s, vector<int>& distance) {
    bool valido = true;
    vector<bool> visto(s.length(), false);
    for(int i = 0; i<s.length() && valido; ++i){
      if(!visto[i]){
        visto[i] = true;
        if(!((distance[s[i]-'a'] < s.length()) && s[distance[s[i]-'a'] + 1 + i] == s[i])){
          valido = false;
        }
        if(valido) visto[distance[s[i]-'a'] + 1 + i] = true;
      }
    }
    return valido;
  }
};