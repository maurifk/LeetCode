#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
  
  bool estaAdentro(vector<vector<int>> img, int x, int y){
    return (x >= 0 && y >= 0 && x<img.size() && y<img[0].size());
  }

  void tiempoNar(vector<vector<int>>& orig, vector<vector<int>>& naranj, int x, int y, int t) {
    naranj[x][y] = t;
    t++;
    if(estaAdentro(orig,x+1,y) && (orig[x+1][y] == 1) && (naranj[x+1][y]>t)) tiempoNar(orig,naranj,x+1,y,t);
    if(estaAdentro(orig,x,y+1) && (orig[x][y+1] == 1) && (naranj[x][y+1]>t)) tiempoNar(orig,naranj,x,y+1,t);
    if(estaAdentro(orig,x-1,y) && (orig[x-1][y] == 1) && (naranj[x-1][y]>t)) tiempoNar(orig,naranj,x-1,y,t);
    if(estaAdentro(orig,x,y-1) && (orig[x][y-1] == 1) && (naranj[x][y-1]>t)) tiempoNar(orig,naranj,x,y-1,t);
  }

  int orangesRotting(vector<vector<int>>& grid) {
    vector<int> res;
    vector<vector<int>> tnars (grid.size(),vector<int>(grid[0].size(),__INT_MAX__));
    
    for (int i = 0; i<grid.size(); ++i){
      for (int j = 0; j<grid[0].size(); ++j){
        if (grid[i][j] == 2){
          tiempoNar(grid, tnars, i, j, 0);
        }
      }
    }

    int maxt = 0;

    for (int i = 0; i<grid.size(); ++i){
      for (int j = 0; j<grid[0].size(); ++j){
        if ((grid[i][j] == 1) && (tnars[i][j] == __INT_MAX__)) return -1;
        if (grid[i][j] == 0) tnars[i][j] = 0;
        maxt = max(maxt,tnars[i][j]);
      }
    }

    return maxt;
  }
};