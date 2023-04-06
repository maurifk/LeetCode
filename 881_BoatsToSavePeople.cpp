#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int izq = 0, der = people.size()-1, barcos = 0;
    
    while(izq <= der){
      if(people[der]+people[izq] > limit){
        barcos++;
        der--;
      } else {
        barcos++;
        der--;
        izq++;
      }
    }
    
    return barcos;
  }
};