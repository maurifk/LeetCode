#include <vector>
using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int aux[nums.size()]; // 0 no visitado / 1 llega / 2 no llega
    for (int i = 0; i<nums.size(); ++i) aux[i] = 0;
    aux[nums.size()-1] = 2;

    for(int i = nums.size()-1; i>=0; --i){
      for(int j = nums[i]; j>0; --j){
        if(i+j >= nums.size()){
          aux[i] = 2; 
          break;
        }
        if(aux[i] != 2){
          if(aux[i+j] == 2){
            aux[i] = 2; 
            break;
          } 
        }
      }
      if (aux[i] == 0) aux[i] = 1;
    }
    return aux[0] == 2;
  }
};