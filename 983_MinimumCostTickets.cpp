#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
  /*
  int calcOPT(vector<int> OPT, int i, int ultD,vector<int>& days, vector<int>& c){
    if (OPT[i] != -1){
      return OPT[i];
    } else if (i == days[days.size()-1]){
      OPT[i] = min(min(c[0],c[1]),c[2]);
      return OPT[i];
    } else if (i < days[days.size()-1]) {
      while (i>days[ultD]){
        ultD++;
      }
      if (i == days[ultD]){
        OPT[i] = min(min(c[0] + calcOPT(OPT, i+1, ultD+1, days,c),c[1] + calcOPT(OPT, i+7, ultD+1, days,c)),c[2] + calcOPT(OPT, i+30, ultD+1, days,c));
      } else {
        OPT[i] = calcOPT(OPT, days[ultD], ultD, days, c);
      }
      return OPT[i];
    } else {
      OPT[i] = 0;
      return 0;
    }
  }

  int mincostTickets(vector<int>& days, vector<int>& costs) {
    int ultD = days[days.size()-1];
    vector<int> OPT (ultD+31,-1);
    return calcOPT(OPT, 1, 0, days, costs);
  }
  */
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> OPT (366,0);
    unordered_set<int> diasViaje;

    for (auto d : days){
      diasViaje.insert(d);
    }

    for (int i = 1; i<=365; ++i){
      if(diasViaje.find(i) != diasViaje.end()){
        OPT[i] = min(OPT[i-1] + costs[0], min(OPT[max(0, i-7)] + costs[1], OPT[max(0, i-30)] + costs[2]));
      } else {
        OPT[i] = OPT[i-1];
      }
    }

    return OPT[365];
  }
};