#include <string>
using namespace std;

class Solution {
public:
  string predictPartyVictory(string senate) {
    int rBans = 0, dBans = 0, n = senate.length();
    int cantElims = 0, cantD = 0, cantR = 0;
    int i = 0;

    for (int i = 0; i < senate.length(); i++){
      if (senate[i] == 'R') cantR++;
      else cantD++;
    }

    while (n-1 != cantElims && cantD != 0 && cantR != 0){
      if (senate[i] == 'R'){
        if (rBans > 0){
          rBans--;
          senate[i] = '-';
          cantElims++;
          cantR--;
        } else {
          dBans++;
        }
      } else if (senate[i] == 'D'){
        if (dBans > 0){
          dBans--;
          senate[i] = '-';
          cantElims++;
          cantD--;
        } else {
          rBans++;
        }
      }

      i = (i+1) % n;
    }

    for (int i = 0; i < senate.length(); i++){
      if (senate[i] != '-') return senate[i] == 'R' ? "Radiant" : "Dire";
    }

    return "-";
  }
};
