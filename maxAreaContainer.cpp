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

  int area (vector<int>& alts, int iuno, int idos){
    return (idos -  iuno) * minimo(alts[iuno], alts[idos]);
  }

  int maxArea(vector<int>& alts) {
    int izq = 0, der = alts.size()-1, maxi = 0;
    while (izq<der){
      maxi = maximo(maxi, area(alts,izq,der));
      if (alts[izq] < alts[der]) {
        izq++;
      } else {
        der--;
      }
    }
    return maxi;
  }
};