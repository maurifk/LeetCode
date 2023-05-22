#include <string>
#include <vector>
using namespace std;

vector<string> solution(const string &s){
  vector<string> res;
  string p;
  
  for (unsigned int i = 0; i<(int)(s.size()/2); ++i){
    p = "";
    p += s[i*2];
    p += s[i*2+1];

    res.push_back(p);
  }
  if (s.size() % 2 == 1){
    p = "";
    p += s[s.size()-1];
    p += '_';
    res.push_back(p);
  }

  return res; // Your code here
}
