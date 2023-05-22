#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
  char bus;
  int slargo;
public:
  bool estaAdentro(int x){
    return (0<=x) && (x<slargo);
  }
  
  void bfs(vector<int>& res, string& s, int i, int dist){
    if(s[i] == bus) res[i] = 0;
    res[i] = min(dist, res[i]);
    if(estaAdentro(i+1) && s[i+1] != bus && res[i+1]>dist+1) bfs(res, s, i+1, dist+1);
    if(estaAdentro(i-1) && s[i-1] != bus && res[i-1]>dist+1) bfs(res, s, i-1, dist+1);
  }
  
  vector<int> shortestToChar(string s, char c) {
    bus = c;
    slargo = s.length();
    vector<int> res(slargo, INT16_MAX);
    
    for(int i = 0; i<slargo; ++i){
      if(s[i] == bus) bfs(res, s, i, 0);
    }
    
    return res;
  }
  
};