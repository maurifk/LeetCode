#include <string>
using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    string s = to_string(x);
    int izq = 0, der = s.size()-1;

    while (izq<der){
      if(s[izq] != s[der]) return false;
      izq++;
      der--;
    }

    return true;
  }
};