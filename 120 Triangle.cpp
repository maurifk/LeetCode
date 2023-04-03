#include <vector>
using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int m = triangle[triangle.size()-1].size();
    vector<vector<int>> OPT(n,vector<int>(m,0));
    
    for(int i = 0; i<m; ++i){
      OPT[n-1][i] = triangle[n-1][i];
    }

    for(int i = n-2; i>=0; --i){
      for(int j = 0; j<m; ++j){
        if(j<=i){
          OPT[i][j] = min(OPT[i+1][j],OPT[i+1][j+1]) + triangle[i][j];
        }
      }
    }
    return OPT[0][0];
  }
};