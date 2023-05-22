#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// LENTISIMO PERO FUNCA B)
class Solution {
public:
  long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto arista: edges){
            int u = arista[0], v = arista[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

    // Estructuras auxiliares
    bool visto[n];
    queue<int> cola;
    unordered_set<int> novistos;
    vector<int> compConex(n,0);

    for (int i = 0; i<n; ++i){
      visto[i] = false;
      novistos.insert(i);
    }
    int u, v;
    int iCompsConex = -1;

    // Algoritmo de verdad - BFS
    do{
      iCompsConex++;
      int org = *novistos.begin();
      cola.push(org);
      visto[org] = true;
      compConex[iCompsConex]++;

      novistos.erase(novistos.find(org));

      while (!cola.empty()){
        u = cola.front();
        cola.pop();

        for(int v: g[u]){
          if (!visto[v]){
            cola.push(v);
            visto[v] = true;
            compConex[iCompsConex]++;
            novistos.erase(novistos.find(v));
          }
        }
      }
    } while (!novistos.empty());

    long long cont = 0;
    long long nodosNoContados = n;


    for (int i = 0; (i<n) && (compConex[i]); ++i){
      nodosNoContados -= compConex[i];
      cont += compConex[i]*nodosNoContados;
    }

    return cont;
  }
};