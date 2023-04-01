#include <string>
using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int si = 0, pi = 0;

    while(si < s.length() && pi < p.length()){
      if (pi >= p.length()) return false;

      if(p[pi] == '.'){
        if(!(pi+1<p.length() && p[pi+1] == '*')){
          si++;
        }
      } else if (p[pi] == '*') {
        while(p[pi-1] == '.' || s[si] == p[pi-1]){
          si++;
          if(si>=s.length()) return true;
        } 
      } else {
        if (s[si] == p[pi]){
          if (!(pi+1<p.length() && p[pi+1] == '*'))
            si++;
        } else {
          if (!(pi+1<p.length() && p[pi+1] == '*')) return false;
        }
      }

      pi++;
    }
    
    if(pi==p.length()) return true;

    string pres = p.substr(pi);

    if(pres.length() % 2 == 1) return false;
    pi = 0;
    
    while(pi<pres.length()){
      if(pres[pi+1] != '*') return false;
      pi++;
      pi++;
    }

    return true;
  }
};

// Fails at "aaa" - "a*a"