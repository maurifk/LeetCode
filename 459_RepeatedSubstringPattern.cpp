#include <string>
using namespace std;

class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    string ss = s + s;
    ss[0] = ss[ss.length()-1] = '_';
    auto i = ss.find(s);
    return (i != string::npos);
  }
};