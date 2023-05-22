#include <string>
#include <regex>
using namespace std;

/*
class Solution {
public:
  int lengthOfLastWord(string s) {
    regex rex("\\w+");
    smatch resul;
    regex_search(s,resul,rex);
    vector<string> strs;

    while (regex_search (s,resul,rex)) {
    strs.push_back(resul[0]);
    s = resul.suffix().str();
    }

    return strs[strs.size()-1].length();
  }
};
*/

class Solution {
public:
  int lengthOfLastWord(string s) {
    int i = s.length()-1, j = 0;
    while(s[i] == ' '){
      i--;
    }
    while(i >= 0 && s[i] != ' '){
      j++;
      i--;
    }
    return j;
  }
};
