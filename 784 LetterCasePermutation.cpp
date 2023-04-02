#include <string>
#include <vector>
using namespace std;

// Should work, idk, gotta ask ChatGPT

class Solution {
public:
  void multi(char s, vector<string>& strs){
    if(strs.size() == 0){
      string ss(1,s);
      if(s >= 'a' && s <='z'){
        string su(1,(char)toupper(s));
        strs.push_back(ss);
        strs.push_back(su);
      } else{
        strs.push_back(ss);
      }
      return;
    }

    if(s >= 'a' && s <='z'){
      for (auto it = strs.rbegin(); it != strs.rend(); it--){
        string temp = *it;
        strs.pop_back();
        strs.push_back(s+temp);
        strs.push_back((char)toupper(s) + temp);
      }
    } else{
      for (auto it = strs.rbegin(); it != strs.rend(); it--){
        string temp = *it;
        strs.pop_back();
        strs.push_back(s+temp);
      }
    }
  }

  vector<string> letterCasePermutation(string s) {
    vector<string> res;
    for (int i = s.length()-1; i>=0; ++i){
      multi(s[i], res);
    }
    return res;
  }
};