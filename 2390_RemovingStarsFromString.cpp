#include <string>
#include <stack>
using namespace std;

/*
class Solution {
public:
  string removeStars(string s) {
    int i = s.find_first_of('*');

    while(i != string::npos){
      int n = s.length();
      if(i+1>n){
        s = s.substr(0,i-2);
      } else {
        s = s.substr(0,i-2) + s.substr(i+1);
      }
      i = s.find_first_of('*');
    }

    return s;
  }
};
*/

class Solution {
public:
  string removeStars(string s) {
    string res = "";

    for(int i = 0; i<s.length(); ++i){
      switch (s[i]){
      case '*':
        res.pop_back();
        break;

      default:
        res.push_back(s[i]);
        break;
      }
    }

    return res;
  }
};