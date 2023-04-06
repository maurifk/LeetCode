#include <vector>
using namespace std;

class NumMatrix {
public:
  vector<vector<int>> sums;
  
  NumMatrix(vector<vector<int>>& matrix) {
    if(matrix.size()==0 || matrix[0].size()==0) return;
    int m = matrix.size(), n = matrix[0].size();
    sums = vector<vector<int>>(m+1,vector<int>(n+1));
    
    for(int i = 1; i<=m; ++i)
      for(int j = 1; j<=n; ++j){
        /*
        if(i==0 && j==0) sums[i][j] = matrix[i][j];
        if(i==0) sums[i][j] = matrix[i][j] + sums[i][j-1];
        if(j==0) sums[i][j] = matrix[i][j] + sums[i-1][j];
        */
        sums[i][j] = matrix[i-1][j-1] + sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1];
      }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    /*
    bool row10 = row1 == 0, col10 = col1 == 0;
    if(row10 && col10) return sums[row2][col2];
    if(row10) return sums[row2][col2] - sums[row2][col1-1];
    if(col10) return sums[row2][col2] - sums[row1-1][col2];
    */
    return (sums[row2+1][col2+1] - sums[row1][col2+1] - sums[row2+1][col1] + sums[row1][col1]);
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */