#include <vector>
using namespace std;

class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n == 0) return true;

    for (int i = 0; i<flowerbed.size(); ++i){
      if (flowerbed[i] == 0 && (((i == 0) && ((i+1 < flowerbed.size()) && (flowerbed[i+1] == 0))) || (i+1 == flowerbed.size()) || (flowerbed[i+1] == 0))){
        flowerbed[i] = 1;
        i++;
        n--;
        if (n == 0) return true;
      } else if (flowerbed[i] == 1){
        i++;
      }
    }
    
    return false;
  }
};