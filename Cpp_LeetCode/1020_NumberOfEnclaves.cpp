#include <vector>
using namespace std;

class Solution {
private:
  bool pared;

public:
  bool estaAdentro(vector<vector<int>> &img, int x, int y){
    return (x >= 0 && y >= 0 && x<img.size() && y<img[0].size());
  }

  void borrarIsla(vector<vector<int>>& image, int sr, int sc, int &area) {
    image[sr][sc] = 0;

    if(!estaAdentro(image,sr+1,sc) || !estaAdentro(image,sr,sc+1) || !estaAdentro(image,sr-1,sc) || !estaAdentro(image,sr,sc-1)) {
      pared = true;
    }

    area++;
    if(estaAdentro(image,sr+1,sc) && image[sr+1][sc] == 1) borrarIsla(image,sr+1,sc,area);
    if(estaAdentro(image,sr,sc+1) && image[sr][sc+1] == 1) borrarIsla(image,sr,sc+1,area);
    if(estaAdentro(image,sr-1,sc) && image[sr-1][sc] == 1) borrarIsla(image,sr-1,sc,area);
    if(estaAdentro(image,sr,sc-1) && image[sr][sc-1] == 1) borrarIsla(image,sr,sc-1,area);
  }

  int numEnclaves(vector<vector<int>>& grid) {
    int area = 0, res = 0;
    pared = false;

    for (int i = 0; i<grid.size(); ++i){
      for (int j = 0; j<grid[0].size(); ++j){
        if (grid[i][j] == 1){
          borrarIsla(grid, i, j, area);
          res += (pared ? 0 : area);
          pared = false;
          area = 0;
        }
      }
    }
    
    return res;
  }
};