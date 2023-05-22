#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
private:
  int buscado;
  vector<int> pots;

public:
  int busq() {
    int izq = 0, der = pots.size()-1;
    while (izq != der) {
      int med = (izq + der) / 2;
      if (pots[med] < buscado) {
        izq = med + 1;
      }
      else {
        der = med;
      }
    }
    return der+1;
  }

  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    vector<int> res;
    sort(potions.begin(),potions.end());
    pots = potions;
    for(int i = 0; i<spells.size(); ++i){
      long long a = trunc(success / spells[i]);
      if (a*spells[i] < success) a++;
      buscado = a;

      // Lambda function !!
      //res.push_back(count_if(potions.begin(),potions.end(), [a](int x){return x>=a;}));
      
      if(potions[potions.size()-1] < a){
        res.push_back(0);
      } else if (potions[0] > a){
        res.push_back(potions.size());
      } else {
        res.push_back(potions.size() - busq() + 1);
      }
    }

    return res;
  }
};