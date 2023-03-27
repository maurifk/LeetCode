#include <string>
#include <set>
using namespace std;

string disemvowel(const string& str) {
  string res;
  set<char> vocales = {'a','e','i','o','u','A','E','I','O','U'};

  for (int i = 0; i<str.length(); ++i){
    if (vocales.count(str[i]) == 0){
      res = res + str[i];
    } 
  }
  return res;
}