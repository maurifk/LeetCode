#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    unsigned int m = grid.size(), n = grid[0].size();
    vector<vector<int>> OPT(m, vector<int>(n));
    OPT[0][0] = grid[0][0];

    for (unsigned int i = 0; i<m; ++i){
      for (unsigned int j = 0; j<n; ++j){
        if ((i != 0) && (j != 0)){
          OPT[i][j] = min(OPT[i-1][j], OPT[i][j-1]) + grid[i][j];
        } else if (i == 0 && j != 0){
          OPT[i][j] = OPT[i][j-1] + grid[i][j];
        } else if (j == 0 && i != 0){
          OPT[i][j] = OPT[i-1][j] + grid[i][j];
        }
      }
    }

    return OPT[m-1][n-1];
  }
};