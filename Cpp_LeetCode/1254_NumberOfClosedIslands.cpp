#include <vector>
using namespace std;

class Solution {
private:
  bool pared;
public:
  bool estaAdentro(vector<vector<int>> &img, int x, int y){
    return (x >= 0 && y >= 0 && x<img.size() && y<img[0].size());
  }

  void borrarIsla(vector<vector<int>>& image, int sr, int sc) {
    image[sr][sc] = 1;

    if(!estaAdentro(image,sr+1,sc) || !estaAdentro(image,sr,sc+1) || !estaAdentro(image,sr-1,sc) || !estaAdentro(image,sr,sc-1)) {
      pared = true;
    }

    if(estaAdentro(image,sr+1,sc) && image[sr+1][sc] == 0) borrarIsla(image,sr+1,sc);
    if(estaAdentro(image,sr,sc+1) && image[sr][sc+1] == 0) borrarIsla(image,sr,sc+1);
    if(estaAdentro(image,sr-1,sc) && image[sr-1][sc] == 0) borrarIsla(image,sr-1,sc);
    if(estaAdentro(image,sr,sc-1) && image[sr][sc-1] == 0) borrarIsla(image,sr,sc-1);
  }

  int closedIsland(vector<vector<int>>& grid) {
    int cont = 0;

    for (int i = 0; i<grid.size(); ++i){
      for (int j = 0; j<grid[0].size(); ++j){
        if (grid[i][j] == 0){
          pared = false;
          borrarIsla(grid, i, j);
          if(!pared) cont++;
        }
      }
    }
    
    return cont;
  }
};