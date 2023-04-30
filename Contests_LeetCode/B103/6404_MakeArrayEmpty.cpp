#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
  long long countOperationsToEmptyArray(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
    int n = nums.size();
    long long k = 0;
    while(!pq.empty()){
      int aElim = pq.top();
      pq.pop();
      auto it = find(nums.begin(), nums.end(), aElim);
      k += distance(nums.begin(), it);
      nums.erase(it);
      k++;
      reverse(nums.begin(), nums.end());
    }
    return k-1;
  }
};
