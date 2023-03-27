#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n);
        for(auto arista: connections){
            int u = arista[0], v = arista[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

    // Estructuras auxiliares
    bool visto[n];
    queue<int> cola;
    set<int> novistos;
    set<pair<int,int>> aristasUtiles;
    set<pair<int,int>> aristasRed;

    for (int i = 0; i<n; ++i){
      visto[i] = false;
      novistos.insert(i);
    }
    int u, v;
    int compsConex = 0;

    // Algoritmo de verdad - BFS
    do{
      compsConex++;
      int org = *novistos.begin();
      cola.push(org);
      visto[org] = true;
      novistos.erase(novistos.find(org));

      while (!cola.empty()){
        u = cola.front();
        cola.pop();

        for(int v: g[u]){
          if (!visto[v]){
            cola.push(v);
            visto[v] = true;
            aristasUtiles.insert({u,v});
            novistos.erase(novistos.find(v));
          } else { // arista redundante
            if(!aristasRed.count({v,u}) && !aristasUtiles.count({v,u})){
              aristasRed.insert({u,v});
            }
          }
        }
      }
    } while (!novistos.empty());

    return (aristasRed.size() >= compsConex-1)? compsConex-1 : -1;
  }
};