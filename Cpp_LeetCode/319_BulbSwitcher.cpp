#include <cmath>
using namespace std;

class Solution {
public:
  bool imparFacts(int n) {
    return (sqrt(n) == trunc(sqrt(n)));
  }

  int bulbSwitch(int n) {
    int cant = 0;
    for(int i = 1; i <= n; i++) {
      if (imparFacts(i)) {
        cant++;
      }
    }
    return cant;
  }
};