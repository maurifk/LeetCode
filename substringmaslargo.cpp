#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> map;
    int izq = 0, der = 0, maxi = 0;;

    while (der < s.length()){
      if(map.count(s[der])){
        maxi = max(maxi, der-izq);
        izq = max(izq, map[s[der]]+1);

      }

      map[s[der]] = der;
      der++;
    }

    return max(maxi, der-izq);
  }
};