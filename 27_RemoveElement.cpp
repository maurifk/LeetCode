#include <vector>
using namespace std;

class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int i = 0;
    int n = nums.size();
    while (i < n) {
      if (nums[i] == val) {
        while (i < n && nums[i] == val) {
          nums[i] = nums[n - 1];
          n--;
        }
        i++;
      } else {
        i++;
      }
    }
    return n;
  }
};
