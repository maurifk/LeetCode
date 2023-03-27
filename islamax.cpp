#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
  bool estaAdentro(vector<vector<int>> img, int x, int y){
    return (x >= 0 && y >= 0 && x<img.size() && y<img[0].size());
  }

  void contarArea(vector<vector<int>>& image, int sr, int sc, int &area) {
    image[sr][sc] = 0;
    area++;
    if(estaAdentro(image,sr+1,sc) && image[sr+1][sc] == 1) contarArea(image,sr+1,sc,area);
    if(estaAdentro(image,sr,sc+1) && image[sr][sc+1] == 1) contarArea(image,sr,sc+1,area);
    if(estaAdentro(image,sr-1,sc) && image[sr-1][sc] == 1) contarArea(image,sr-1,sc,area);
    if(estaAdentro(image,sr,sc-1) && image[sr][sc-1] == 1) contarArea(image,sr,sc-1,area);
  }

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int area = 0, maxArea = 0;
    for (int i = 0; i<grid.size(); ++i){
      for (int j = 0; j<grid[0].size(); ++j){
        if (grid[i][j] == 1){
          contarArea(grid,i,j,area);
          maxArea = max(area,maxArea);
          area = 0;
        }
      }
    }
    
    return maxArea;
  }
};