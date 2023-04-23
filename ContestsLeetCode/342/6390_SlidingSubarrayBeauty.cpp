#include <vector>
#include <algorithm>
using namespace std;

// Correct answer for the prompt, uses the fact that nums is bounded to keep a frequency array -> O(n)
class Solution {
public:
  vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    int n = nums.size();
    vector<int> res(n-k+1, 0);
    vector<int> freqsubv(101, 0);
    for(int i=0; i<k; i++){
      freqsubv[nums[i]+50]++;
    }

    for(int i=0; i<n-k+1; i++){
      int cont = x;
      for(int j = 0; j<51; j++){
        cont -= freqsubv[j];
        if(cont <= 0){
          res[i] = j-50;
          break;
        }
      }
      
      if (i+k < n){
        freqsubv[nums[i+k]+50]++;
        freqsubv[nums[i]+50]--;
      }
    }

    return res;
  }
};