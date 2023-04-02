#include <vector>
#include <unordered_set>
#include <set>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
  int findShortestCycle(int n, vector<vector<int>>& edg) {
    vector<vector<int>> g(n);
    for (auto ari : edg){
      g[ari[0]].push_back(ari[1]);
      g[ari[1]].push_back(ari[0]);
    }

    // Estructuras auxiliares
    int lento, rapido;
    vector<bool> visto(n, false);
    int minLargo = INT32_MAX, pre, j;
    bool finC = false;
    queue<int> cola;
    unordered_set<int> novistos;
    set<pair<int,int>> aristasUtiles;

    for (int i = 0; i<n; ++i){
      novistos.insert(i);
    }
    int u, v;

    // Algoritmo de verdad - BFS
    do{
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
            if(!aristasUtiles.count({v,u})){
              // Ciclo
              int padre, hijo;
              vector<bool> visC(n,false);
              visC[u] = true;
              visC[v] = true;
              int cont = 0;
              queue<pair<int,int>> colaC;
              colaC.push({u,v});
              while (!colaC.empty() && !finC){
                padre = colaC.front().second;
                hijo = colaC.front().first;
                cont++;
                for (int vC : g[hijo]){
                  if(vC != padre){
                    if(!visC[vC]){
                      colaC.push({vC,hijo});
                      visC[vC] = true;
                    } else {
                      minLargo = min(minLargo,cont+1);
                    }
                  }
                }
              }
              
            }
          }
        }
      }
    } while (!novistos.empty());

    return (aristasRed.size() >= compsConex-1)? compsConex-1 : -1;
  }

    /*
    for (unsigned int i = 0; i<n; ++i){
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
          

          minLargo = min(minLargo,cont);
          finC = true;
        }
      }
    }
    return minLargo;
  }
  */
};