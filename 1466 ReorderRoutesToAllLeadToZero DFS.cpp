#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
  int dfs(vector<vector<int>> &g, vector<bool> &vis, int u){
    int darV = 0;
    vis[u] = true;
    for (auto v : g[u])
      if (!vis[abs(v)]) darV += dfs(g,vis,abs(v)) + (v > 0);
    
    return darV;
  }

  int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<int>> g(n);
    vector<bool> vis(n, false);
    for (auto aris : connections){
      g[aris[0]].push_back(aris[1]);
      g[aris[1]].push_back(-aris[0]);
    }
    return dfs(g,vis,0);
  }
};