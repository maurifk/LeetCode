#include <vector>
using namespace std;

class Solution {
public:
  long long zeroFilledSubarray(vector<int>& nums) {
    int nroZerosSeg = 1;
    long long res = 0;

    for (long long i = 0; i<nums.size(); ++i){
      if(nums[i] == 0){
        res += nroZerosSeg;
        nroZerosSeg++;
      } else {
        nroZerosSeg = 1;
      }
    }

    return res;
  }
};