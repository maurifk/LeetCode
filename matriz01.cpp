#include <vector>
using namespace std;

class Solution {
public:

  bool estaAdentro(vector<vector<int>> &img, int x, int y){
    return (x >= 0 && y >= 0 && x<img.size() && y<img[0].size());
  }

  void llenarAux(vector<vector<int>> &ori, 
                  vector<vector<int>> &mat, 
                  int x, int y, int dist){
    if(!ori[x][y]) dist = 0;
    mat[x][y] = dist;
    if(estaAdentro(ori,x+1,y) && mat[x+1][y] && (mat[x+1][y]>dist+1)) llenarAux(ori,mat,x+1,y,dist+1);
    if(estaAdentro(ori,x,y+1) && mat[x][y+1] && (mat[x][y+1]>dist+1)) llenarAux(ori,mat,x,y+1,dist+1);
    if(estaAdentro(ori,x-1,y) && mat[x-1][y] && (mat[x-1][y]>dist+1)) llenarAux(ori,mat,x-1,y,dist+1);
    if(estaAdentro(ori,x,y-1) && mat[x][y-1] && (mat[x][y-1]>dist+1)) llenarAux(ori,mat,x,y-1,dist+1);
  }
  
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    vector<vector<int>> res (mat.size(), vector<int>(mat[0].size(),__INT_MAX__));

    for (int i = 0; i<mat.size(); ++i){
      for (int j = 0; j<mat[0].size(); ++j){
        if(!mat[i][j]) {
          llenarAux(mat, res, i, j, 0); 
        }
      }
    }

    return res;
  }
};