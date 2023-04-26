#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
  bool esPrimo(int n){
    if (n == 0) return false;
    if (n == 1) return false;
    for(int i = 2; i*i<=n; ++i){
      if(n%i == 0) return false;
    }
    return true;
  }

  int diagonalPrime(vector<vector<int>>& nums) {
    int n = nums.size(), maxi = 0;
    for(int i = 0; i < n; ++i){
      if (esPrimo(nums[i][i]))
        maxi = max(maxi, nums[i][i]);
      if(esPrimo(nums[i][n-i-1]))
        maxi = max(maxi, nums[i][n-i-1]);
    }
    return maxi;
  }
};