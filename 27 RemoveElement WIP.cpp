#include <vector>
using namespace std;

class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int izq = 0, der = nums.size()-1;

    if (izq == der){
      return (nums[izq] == val)? 0 : 1;
    }

    while (izq<der){
      if(nums[izq] == val){
        while(der >= 0 && nums[der] == val){
          der--;
        }
        if (der == -1) return 0;
        nums[izq] = nums[der];
        der--;
      }
      izq++;
    }
    return der+1;
  }
};