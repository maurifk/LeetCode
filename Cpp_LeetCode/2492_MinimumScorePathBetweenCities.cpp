#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int minScore(int n, vector<vector<int>>& roads) {
    // roads[i] = {ciudad A, ciudad B, largo calle A <-> B}

    // Generacion grafo util
    // Iniciarlo
    unordered_map<int, unordered_map<int, int>> g;
        for(auto road: roads){
            int u = road[0], v = road[1], w = road[2];
            g[u][v] = g[v][u] = w;
        }

    // Estructuras auxiliares
    bool visto[n+1];
    queue<int> cola;

    for (int i = 0; i<=n; ++i){
      visto[i] = false;
    }
    cola.push(1);
    int mini = __INT_MAX__;
    int u, v, peso;

    // Algoritmo de verdad
    while (!cola.empty()){
      u = cola.front();
      cola.pop();

      for(auto adj: g[u]){
        v = adj.first;
        peso = adj.second;

        if (!visto[v]){
          cola.push(v);
          visto[v] = true;
        }
        mini = min(mini, g[u][v]);
      }
    }

    return mini;
  }
};