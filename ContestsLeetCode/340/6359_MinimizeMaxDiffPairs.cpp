#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;
// ChatGPT ??
/*
class Solution {
public:

  int paresConDifD(vector<int>& nums, int d){
    int n = nums.size();
    int izq = 0, der = 0, cant = 0;
    while (izq < n){
      while(der < n && (nums[der]-nums[izq] <= d)){
        der++;
      }
      cant += der-izq-1;
      izq++;
    }
    return cant;
  }
*/

class Solution {
public:
    bool canPlacePairs(vector<int>& nums, int maxDiff, int pairs) {
        int n = nums.size();
        int count = 0, left = 0, right = 0;
        while (left < n && right < n) {
            while (right < n && nums[right] - nums[left] <= maxDiff) right++;
            count += right - left - 1;
            left++;
        }
        return count >= pairs;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums[nums.size()-1]-nums[0], mid;
        while (left < right) {
            mid = left + (right-left)/2;
            if (canPlacePairs(nums, mid, p)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};