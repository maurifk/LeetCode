#include <string>
using namespace std;

class Accumul {
public:
  static string accum(const string &s){
    string res;

    for (int i = 0; i<s.size(); ++i){
      for (int j = 1; j<=i+1; ++j){
        if (j == 1){
          res = res + (char)(toupper(s[i]));
        } else {
          res = res + (char)(tolower(s[i]));
        }
      }
      if(i != s.size()-1){
        res = res + '-';
      }
    }
    return res;
  }
};