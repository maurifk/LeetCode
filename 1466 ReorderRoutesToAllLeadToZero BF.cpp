#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  // LENTO, TRISTE :c pero, fue total intuicion, vibes
  bool todosTrue(vector<bool> vec){
    for (int i = 0; i<vec.size(); ++i){
      if(!vec[i]) return false;
    }
    return true;
  }

  int minReorder(int n, vector<vector<int>>& connections) {
    vector<bool> nodosPB(n,false);
    vector<bool> callesutiles(connections.size(), false);
    int cont = 0;
    nodosPB[0] = true;

    while (!todosTrue(nodosPB)){
      for (int i = 0; i<connections.size(); ++i){
        if (!callesutiles[i]){
          if (!nodosPB[connections[i][0]] && nodosPB[connections[i][1]]){
            nodosPB[connections[i][0]] = true;;
            callesutiles[i] = true;
          } else if (nodosPB[connections[i][0]] && !nodosPB[connections[i][1]]){
            // Doy vuelta la calle i
            cont++;
            nodosPB[connections[i][1]] = true;
            callesutiles[i] = true;
          } else if (nodosPB[connections[i][0]] && nodosPB[connections[i][1]]){
            callesutiles[i] = true;
          }
        }
      }
    }

    return cont;
  }
};