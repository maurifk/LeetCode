#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  bool estaAdentro(int n, int x, int y){
    return (0<=x) && (0<=y) && (x<n) && (y<n);
  }

  pair<int,int> sigMov(vector<vector<int>>& g, int i, int x, int y){
    bool enc = false;
    int n = g.size();
    pair<int,int> res = {-1,-1};

    if(!enc && estaAdentro(n,x-2,y-1) && g[x-2][y-1] == i+1){enc = true; res = {x-2,y-1};};
    if(!enc && estaAdentro(n,x-2,y+1) && g[x-2][y+1] == i+1){enc = true; res = {x-2,y+1};};
    if(!enc && estaAdentro(n,x+2,y-1) && g[x+2][y-1] == i+1){enc = true; res = {x+2,y-1};};
    if(!enc && estaAdentro(n,x+2,y+1) && g[x+2][y+1] == i+1){enc = true; res = {x+2,y+1};};
    if(!enc && estaAdentro(n,x-1,y-2) && g[x-1][y-2] == i+1){enc = true; res = {x-1,y-2};};
    if(!enc && estaAdentro(n,x+1,y-2) && g[x+1][y-2] == i+1){enc = true; res = {x+1,y-2};};
    if(!enc && estaAdentro(n,x-1,y+2) && g[x-1][y+2] == i+1){enc = true; res = {x-1,y+2};};
    if(!enc && estaAdentro(n,x+1,y+2) && g[x+1][y+2] == i+1){enc = true; res = {x+1,y+2};};

    return res;

  }

  bool checkValidGrid(vector<vector<int>>& grid) {
    int n = grid.size(), i = 0, x = 0, y = 0;
    bool valido = true;
    pair<int,int> smov;

    while (valido && (i<n*n-1)){
      if(grid[0][0] != 0){
        valido = false;
        break;
      }
      smov = sigMov(grid, i, x, y);
      if (smov.first == -1){
        valido = false;
      } else {
        x = smov.first;
        y = smov.second;
        i++;
      }
    }

    return valido;
  }
};