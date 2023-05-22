#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    unordered_set<int> setv;
    
    for (int i = 0; i<nums.size(); ++i){
      auto it = setv.find(nums[i]);
      if(it != setv.end()){
        setv.erase(it);
      } else {
        setv.insert(nums[i]);
      }
    }
    return *setv.begin();
  }
};

// Clever Solution, uses that XOR is commutative
/*
class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int c = 0;
    for (int i = 0; i<nums.size(); ++i){
      c^=nums[i];
    }
    return c;
  }
};
*/