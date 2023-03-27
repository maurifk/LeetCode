#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pi;

class Solution {
public:
  int minScore(int n, vector<vector<int>>& roads) {
    // roads[i] = {ciudad A, ciudad B, largo calle A <-> B}

    // Generacion grafo util
    // Iniciarlo
    vector<vector<int>> g(n+1, vector<int>(n+1));

    // Pasaje de formato ?? a util
    for(int i = 0; i<roads.size(); ++i){
      g[roads[i][0]][roads[i][1]] = roads[i][2];
      g[roads[i][1]][roads[i][0]] = roads[i][2];
    }

    // Estructuras auxiliares
    int dist[n+1];
    int padre[n+1];
    bool visto[n+1];
    priority_queue<pi, vector<pi>, greater<pi> > cola;

    for (int i = 0; i<=n; ++i){
      dist[i] = __INT_MAX__;
      padre[i] = 0;
      visto[i] = false;
    }
    dist[1] = 0;
    cola.push({0,1});
    int u;

    // Algoritmo de verdad
    while (!visto[n]){
      do{
        u = cola.top().second;
        cola.pop();
      }while(visto[u]);
      visto[u] = true;

      for(int v = 1; v<=n; ++v){
        if(g[u][v] != 0){ // Adyacentes
          if (!visto[v]){
            if (dist[v] > (dist[u] + g[u][v])){
              dist[v] = dist[u] + g[u][v];
              padre[v] = u;
              cola.push({dist[v],v});
            }
          }
        }
      }
    }

    return dist[n];
  }
};