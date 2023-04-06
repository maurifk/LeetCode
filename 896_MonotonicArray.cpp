#include <vector>
using namespace std;

class Solution {
public:
  bool isMonotonic(vector<int>& nums) {
    bool valido = true;
    int estado = 0;
    if (nums[0]>nums[nums.size()-1]) estado = 1;
    else if (nums[0]<nums[nums.size()-1]) estado = 2;

    for(int i = 1; i<nums.size() && valido; ++i){
      switch (estado)
      {
      case 0:
        if(nums[i] != nums[i-1]) valido = false;
        break;
      case 1:
        if(nums[i] > nums[i-1]) valido = false;
        break;
      case 2:
        if(nums[i] < nums[i-1]) valido = false;
        break;
      }
    }

    return valido;
  }
};