#include <string>
using namespace std;

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    int i = 0, j = 0;
    string res = "";
    bool turno = true;

    while (i<word1.length() || j<word2.length()){
      if (i<word1.length() && j<word2.length()){
        if (turno){
          res += word1[i];
          i++;
        } else {
          res += word2[j];
          j++;
        }
        turno = !turno;
      } else if (i<word1.length()){
        res += word1.substr(i);
        i = word1.length();
      } else{
        res += word2.substr(j);
        j = word2.length();
      }
    }

    return res;
  }
};