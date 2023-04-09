#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
  int longestCycle(vector<int>& g) {
    int n = g.size();
    unordered_map<int, int> mapa;
    //vector<bool> vis(n, false), vistosEsteLoop(n,false);
    unordered_set<int> setNoV, largos, vistosEsteLoop;
    for (int i = 0; i<n; ++i){
      setNoV.insert(i);
    }

    int t = 0, u, v;
    queue<int> cola;

    do {
      t = 0;
      int org = *setNoV.begin();
      cola.push(org);
      //vis[org] = true;
      mapa[org] = t;
      setNoV.erase(setNoV.find(org));
      vistosEsteLoop.insert(org);

      while (!cola.empty()){
        u = cola.front();
        cola.pop();
        t++;
        if (g[u] != -1){
          v = g[u];
        } else {
          cola.pop();
          break;
        }

        if(setNoV.count(v)){
          cola.push(v);
          setNoV.erase(setNoV.find(v));
          vistosEsteLoop.insert(v);
          mapa[v] = t;
        } else {
          if(vistosEsteLoop.count(v)){
            largos.insert(t - mapa[v]);
          } else {
            break;
          }
        }
      }
      //fill(vistosEsteLoop.begin(),vistosEsteLoop.end(), false);
      vistosEsteLoop.clear();    
    } while (!setNoV.empty());
    
    int maxt = 0;

    for (int i : largos){
      maxt = max(maxt, i);
    }

    return (largos.size() > 0) ? maxt : -1;
  }
};

int main(){
  vector<int> aristas = {436,513,40,410,384,-1,283,447,138,48,322,444,-1,-1,71,481,491,138,475,5,-1,374,427,-1,124,200,-1,13,530,-1,248,-1,-1,56,138,393,-1,106,389,164,368,-1,372,-1,-1,530,422,530,-1,282,222,-1,192,-1,437,-1,146,-1,411,382,295,283,-1,-1,504,501,526,-1,-1,-1,-1,416,391,-1,536,294,191,85,536,473,543,-1,-1,-1,-1,-1,490,119,-1,-1,410,202,-1,409,-1,341,213,-1,-1,-1,258,54,321,-1,190,425,35,-1,-1,60,527,-1,254,532,381,250,199,-1,537,443,-1,511,19,-1,418,230,216,152,301,488,196,94,513,190,432,-1,-1,356,417,482,-1,393,157,191,515,436,-1,-1,217,-1,266,56,-1,15,86,-1,368,271,44,85,144,527,444,-1,537,493,-1,-1,276,-1,37,467,263,366,453,79,-1,-1,281,324,-1,-1,-1,-1,238,132,365,434,-1,-1,128,349,-1,358,545,-1,178,232,421,-1,168,-1,324,-1,254,77,28,536,-1,-1,325,148,5,486,-1,-1,27,424,-1,-1,275,-1,-1,-1,186,203,189,249,-1,-1,393,50,347,-1,14,395,-1,441,193,498,-1,331,276,-1,356,361,-1,301,503,380,-1,358,-1,485,23,-1,352,236,-1,-1,80,-1,-1,52,-1,454,-1,165,181,-1,-1,50,-1,280,537,87,-1,21,-1,-1,413,-1,-1,211,-1,355,73,233,18,540,395,155,313,523,184,369,68,292,279,-1,124,516,200,224,104,310,120,523,206,-1,-1,-1,117,-1,-1,-1,-1,138,241,-1,-1,-1,-1,28,92,-1,11,-1,140,367,94,-1,-1,21,507,334,364,-1,110,213,200,93,85,371,332,204,165,532,148,386,500,480,478,444,-1,-1,34,103,467,56,409,412,-1,192,188,291,-1,-1,-1,-1,-1,418,98,322,-1,189,-1,-1,240,-1,155,117,141,447,94,-1,282,-1,268,374,411,-1,442,-1,402,-1,-1,232,427,168,466,397,25,-1,249,-1,446,168,409,52,31,332,-1,430,406,478,-1,183,75,238,-1,29,-1,14,-1,451,228,380,-1,-1,357,-1,60,-1,-1,131,149,162,-1,263,-1,-1,-1,-1,338,-1,336,20,-1,-1,321,430,417,-1,317,544,-1,266,88,-1,235,403,373,500,66,-1,-1,536,89,439,502,440,-1,93,-1,110,-1,-1,284,-1,-1,123,145,343,406,-1,260,352,-1,5,440,76,2,433,-1,142,538,-1,462,287,-1,-1,164,252,219,490,535,272,383,-1,146,331,358,-1,-1,-1,54,-1,-1,-1,-1,51,364,223,30,-1,-1,336,225,-1,32,-1,-1,111,343,294,-1,-1,-1,522,62,332,356,333,371,452}; // -1
  Solution sol;

  cout<<sol.longestCycle(aristas);
  return 0;
}