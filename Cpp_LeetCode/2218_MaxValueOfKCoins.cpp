#include <vector>
using namespace std;

// TLE

class Solution {
public:
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    int n = piles.size();
    vector<vector<int>> sumaM(n, vector<int>(k+1, 0));
    for (int i = 0; i<n; ++i){
      for(int j = 1; j<=k; ++k){
        if(j-1<piles[i].size()){
          sumaM[i][j] = sumaM[i][j-1] + piles[i][j-1];
        }
      }
    }

    vector<vector<int>> OPT(n, vector<int>(k+1, 0));

    for(int i = 1; i<=k; ++i){
      OPT[0][i] = sumaM[1][i];
    }
    
    for(int i = 1; i<n; ++i){
      for(int j = 0; j<=n; ++j){
        OPT[i][j] = OPT[i-1][n-j]+sumaM[i][j];
      }
    }

    int maxi = INT_MIN;
    for(int i = 0; i<=k; ++i){
      maxi = max(maxi,OPT[n-1][i]);
    }

    return maxi;
  }
};