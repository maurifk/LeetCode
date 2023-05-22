#include<string>
#include <vector>
using namespace std;

bool scramble(const string& s1, const string& s2){
  if(s2.length() > s1.length()) return false;
  vector<int> letrass1(26,0);
  vector<int> letrass2(26,0);

  for (int i = 0; i<s1.length(); ++i){
    if(i<s2.length()){
      letrass2[s2[i]-'a']++;
    }
    letrass1[s1[i]-'a']++;
  }

  bool val = true;
  for (int i = 0; i<26 && val; ++i){
    if(letrass1[i]<letrass2[i]) val = false;
  }

  return val;
}