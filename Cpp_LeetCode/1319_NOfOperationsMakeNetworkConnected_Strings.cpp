#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// MAS LENTO <-> RIP
// Tried to optimize, failed
class Solution {
public:
  pair<int,int> recuperarVerts(string uv){
    int pos = uv.find(' ');
    return {stoi(uv.substr(0,pos)), stoi(uv.substr(pos+1))};
  }

  string generarString(pair<int,int> uv){
    return (to_string(uv.first) + ' ' + to_string(uv.second));
  }

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
    unordered_set<int> novistos;
    unordered_set<string> aristasUtiles;
    unordered_set<string> aristasRed;

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
            aristasUtiles.insert(generarString({u,v}));
            novistos.erase(novistos.find(v));
          } else { // arista redundante
            if(!aristasRed.count(generarString({v,u})) && !aristasUtiles.count(generarString({v,u}))){
              aristasRed.insert(generarString({u,v}));
            }
          }
        }
      }
    } while (!novistos.empty());

    return (aristasRed.size() >= compsConex-1)? compsConex-1 : -1;
  }
};