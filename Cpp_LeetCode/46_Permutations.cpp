#include <vector>
using namespace std;

class Solution {
private: 
  vector<int>& temp;
  vector<vector<int>> res;
  
public:
  void auxC(vector<int>& nums, vector<bool> puestos){
    if (temp.size() == nums.size()){
      res.push_back(temp);
      return;
    }

    for (int i = 0; i<nums.size(); ++i){
      if (puestos[i]) return;

      puestos[i] = true;
      temp.push_back(nums[i]);
      auxC(nums, puestos);
      temp.pop_back();
      puestos[i] = false;
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> yaPuestos(nums.size(), false);
    auxC(nums, yaPuestos);
    return res;
  }
};