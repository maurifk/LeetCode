#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    for (auto e : edges){
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    //vector<bool> vis(n, false);
    unordered_set<int> setNoV;
    for (int i = 0; i<n; ++i){
      setNoV.insert(i);
    }

    int u, v, compsComp = 0;
    queue<int> cola;
    unordered_set<int> vistosEsteLoop;

    do {
      int org = *setNoV.begin();
      cola.push(org);
      //vis[org] = true;
      setNoV.erase(setNoV.find(org));
      vistosEsteLoop.insert(org);

      while (!cola.empty()){
        u = cola.front();
        cola.pop();

        for (int i : g[u]){
          if (setNoV.find(i) != setNoV.end()){
            vistosEsteLoop.insert(i);
            setNoV.erase(setNoV.find(i));
            cola.push(i);
          }
        }
      }

      int cantEnComp = vistosEsteLoop.size(), arisEnComp = 0;

      for (auto e : edges){
        if (vistosEsteLoop.find(e[0]) != vistosEsteLoop.end()){
          arisEnComp++;
        }
      }

      if (arisEnComp == (cantEnComp - 1)*(cantEnComp)/2)
        compsComp++;

      vistosEsteLoop.clear();

    } while (!setNoV.empty());

    return compsComp;
  }
};
