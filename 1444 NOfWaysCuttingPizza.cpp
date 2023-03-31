#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int dfs(int m, int n, int k, int r, int c, vector<vector<vector<int>>>& OPT, vector<vector<int>>& preSuma){
    if (preSuma[r][c] == 0) return 0;
    if (k == 0) return 1;
    if (OPT[k][r][c] != -1) return OPT[k][r][c];
    int res = 0;
    
    for(int nr = r+1; nr < m; ++nr)
      if (preSuma[r][c] - preSuma[nr][c] > 0)
        res = (res + dfs(m,n,k-1,nr,c,OPT,preSuma)) % 1000000007;
    
    for(int nc = c+1; nc < n; ++nc)
      if(preSuma[r][c] - preSuma[r][nc] > 0)
        res = (res + dfs(m,n,k-1,r,nc,OPT,preSuma)) % 1000000007;
    
    return OPT[k][r][c] = res;
  }
  
  int ways(vector<string>& pizza, int k) {
    int m = pizza.size(), n = pizza[0].size();
    vector<vector<vector<int>>> OPT(k,vector<vector<int>>(m, vector<int>(n,-1)));
    vector<vector<int>> preSuma(m+1,vector<int>(n+1,0));
    
    for(int r = m-1; r >= 0; --r)
      for (int c = n-1; c >= 0; --c)
        preSuma[r][c] = preSuma[r+1][c] + preSuma[r][c+1] - preSuma[r+1][c+1] + (pizza[r][c] == 'A');
    
    return dfs(m,n,k-1,0,0,OPT,preSuma);
  }
};