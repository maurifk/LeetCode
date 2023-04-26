#include <vector>
using namespace std;

class Solution {
public:
  vector<int> evenOddBit(int n) {
    bool par = true;
    vector<int> res(2);
    while(n>1){
      if(par){
        res[0] += n%2;
      } else{
        res[1] += n%2;
      }
      par = !par;
      n /= 2;
    }
    
    if(par){
      res[0] += 1;
    } else{
      res[1] += 1;
    }

    return res;
  }
};