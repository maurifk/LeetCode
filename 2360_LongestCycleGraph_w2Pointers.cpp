#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  int longestCycle(vector<int>& edges) {
    int lento, rapido;
    vector<bool> vis(edges.size(), false);
    int maxLargo = -1, pre, j;
    bool finC = false;

    for (unsigned int i = 0; i<edges.size(); ++i){
      finC = false;
      j = 0;
      if(edges[i] == -1) continue;
      if(vis[i]) continue;
      lento = i; rapido = i;
      while (edges[rapido] != -1 && edges[edges[rapido]] != -1 && !finC){
        j++;
        lento = edges[lento];
        vis[lento] = true;
        rapido = edges[edges[rapido]];

        if(rapido == lento){
          int cont = 0;
          
          do {
            cont++;
            pre = lento;
            lento = edges[lento];
            edges[pre] = -1;
          } while (rapido != lento);
          

          if (cont > maxLargo) maxLargo = cont;
          finC = true;
        }
      }
    }
    return maxLargo;
  }
};

int main(){
  vector<int> aristas = {1,2,3};
  Solution sol;

  cout<<sol.longestCycle(aristas);
  return 0;
}