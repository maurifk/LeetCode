#include <vector>
using namespace std;

class Solution {
public:
  bool estaAdentro(vector<vector<int>> img, int x, int y){
    return (x >= 0 && y >= 0 && x<img.size() && y<img[0].size());
  }

  vector<vector<int>> auxInundacion(vector<vector<int>>& image, int sr, int sc, int colOrg, int color) {
    image[sr][sc] = color;
    if(estaAdentro(image,sr+1,sc) && image[sr+1][sc] == colOrg) auxInundacion(image,sr+1,sc,colOrg,color);
    if(estaAdentro(image,sr,sc+1) && image[sr][sc+1] == colOrg) auxInundacion(image,sr,sc+1,colOrg,color);
    if(estaAdentro(image,sr-1,sc) && image[sr-1][sc] == colOrg) auxInundacion(image,sr-1,sc,colOrg,color);
    if(estaAdentro(image,sr,sc-1) && image[sr][sc-1] == colOrg) auxInundacion(image,sr,sc-1,colOrg,color);

    return image;
  }

  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if (color == image[sr][sc]) return image;
    return auxInundacion(image,sr,sc,image[sr][sc],color);
  }
};