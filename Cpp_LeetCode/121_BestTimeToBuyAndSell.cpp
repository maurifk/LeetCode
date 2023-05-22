#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int izq = 0, der = 1, profmax = 0;
    while (der < prices.size()) {
      int prof = prices[der] - prices[izq];
      if (prof > 0) {
        profmax = max(profmax, prof);
      } else {
        izq = der;
      }
      der++;
    }
    return profmax;
  }
};
