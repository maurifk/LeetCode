#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(),satisfaction.end());
    vector<int> OPT(satisfaction.size(),0);
    int ac = 0, t = 1, maxa = INT32_MIN;

    for(int i = 0; i<satisfaction.size(); ++i){
      ac = 0;
      t = 1;
      for (int j = i; j<satisfaction.size(); ++j){
        ac += satisfaction[j] * t;
        t++;
      }
      OPT[satisfaction.size()-i-1] = ac;
      maxa = max(maxa, ac);
    }
    return (maxa>=0) ? maxa : 0;
  }
};