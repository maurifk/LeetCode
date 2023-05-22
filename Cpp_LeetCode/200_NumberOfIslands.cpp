#include <vector>
using namespace std;

class Solution {
public:
  bool estaAdentro(vector<vector<char>> &img, int x, int y){
    return (x >= 0 && y >= 0 && x<img.size() && y<img[0].size());
  }

  void borrarIsla(vector<vector<char>>& image, int sr, int sc) {
    image[sr][sc] = '0';
    if(estaAdentro(image,sr+1,sc) && image[sr+1][sc] == '1') borrarIsla(image,sr+1,sc);
    if(estaAdentro(image,sr,sc+1) && image[sr][sc+1] == '1') borrarIsla(image,sr,sc+1);
    if(estaAdentro(image,sr-1,sc) && image[sr-1][sc] == '1') borrarIsla(image,sr-1,sc);
    if(estaAdentro(image,sr,sc-1) && image[sr][sc-1] == '1') borrarIsla(image,sr,sc-1);
  }

  int numIslands(vector<vector<char>>& grid) {
    int cont = 0;
    for (int i = 0; i<grid.size(); ++i){
      for (int j = 0; j<grid[0].size(); ++j){
        if (grid[i][j] == '1'){
          borrarIsla(grid,i,j);
          cont++;
        }
      }
    }
    
    return cont;
  }
};