#include <vector>
#include <numeric>
using namespace std;

// Sol funcional 🥵

class Solution {
public:
  int arraySign(vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 1, [&](int a, int b) { return a == 0 || b == 0 ? 0 : ((a > 0 && b > 0) || (a < 0 && b < 0) ? 1 : -1);});
  }
};
