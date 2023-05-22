#include <vector>
using namespace std;

class Solution {
public:
  int maximo(int a, int b){
    return a > b ? a : b;
  }

  int minimo(int a, int b){
    return a > b ? b : a;
  }

  int trap(vector<int>& alts) {
    int maxi = 0, maxd = 0, j;
    int n = alts.size();
    int res = 0, agua;
    vector<int> desdeIzq(n);
    vector<int> desdeDer(n);

    for (int i = 0; i<alts.size(); ++i){
      j = alts.size() - 1 - i;
      desdeIzq[i] = maxi;
      desdeDer[j] = maxd;
      maxi = maximo(maxi, alts[i]);
      maxd = maximo(maxd, alts[j]);
    }

    for (int i = 0; i<alts.size(); ++i){
      agua = minimo(desdeDer[i], desdeIzq[i]) - alts[i];
      res += agua > 0 ? agua : 0;
    }

    return res;
  }
};
