#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int izq = 0;
    for(int i = 0; i<nums.size(); ++i){
      if(nums[i] != nums[izq]){
        izq++;
        nums[izq] = nums[i];
      }
    }
    return izq+1;
  }
};