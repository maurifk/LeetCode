#include <vector>
using namespace std;

class Solution {
public:
  int binarySearch(vector<int>& nums, int target) {
    //Do binary search to find an instance of target in nums
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return left < nums.size() && nums[left] == target ? left : -1;
  }

  vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.size() == 0) return {-1, -1};
    int busq = binarySearch(nums, target);
    
    if (busq == -1) {
      return {-1, -1};
    } else {
      int left = busq;
      int right = busq;
      while (left > 0 && nums[left - 1] == target) {
        left--;
      }
      while (right < nums.size() - 1 && nums[right + 1] == target) {
        right++;
      }

      return {left, right};
    }
  }
};