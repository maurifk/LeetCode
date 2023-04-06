#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int partitionString(string s) {
    unordered_set<char> setC;
    int subs = 1;
    
    for(int i = 0; i<s.length(); ++i){
      if(setC.find(s[i]) != setC.end()){
        subs++;
        setC.clear();
      } else {
        setC.insert(s[i]);
      }
    }
    return subs;
  }
};