#include <string>
using namespace std;
/*
class Solution {
public:
  int strStr(string haystack, string needle) {
    int ind = 0, j = 0;
    bool encontrado = false;

    for(int i = 0; i<haystack.length() && !encontrado; ++i){
      if(j<needle.length()){
        if(haystack[i] == needle[j]){
          j++;
          if(j==needle.length()) return ind;
        } else{
          i = ind;
          ind = i+1;
          j = 0;
        }
      }
    }
    return -1;
  }
};
*/

class Solution {
public:
  int strStr(string haystack, string needle) {
    auto i = haystack.find(needle);
    return (i != string::npos) ? i : -1;
  }
};