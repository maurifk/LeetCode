#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maximizeSum(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return nums[n-1] * k + ((k*(k-1))/2);
  }
};
