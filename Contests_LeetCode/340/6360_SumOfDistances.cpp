#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
  vector<long long> distance(vector<int>& nums) {
    unordered_map<int, vector<int>> mapa;
    for(int i = 0; i < nums.size(); ++i){
      mapa[nums[i]].push_back(i);
    }

    vector<long long> res(nums.size());
    /*
    for(int i = 0; i<nums.size(); ++i){
      long long cont = 0;
      for (int ind : mapa[nums[i]]){
        if(ind != i){
          cont += abs(i-ind);
        }
      }
      res.push_back(cont);
    }
    */
    for(auto& [num, indices] : mapa){
      int n = indices.size();
      vector<long long> prefix_sum(n, 0);
      prefix_sum[0] = indices[0];
      for(int i = 1; i < n; ++i){
        prefix_sum[i] = prefix_sum[i-1] + indices[i];
      }

      long long suffix_sum = 0;
      for(int i = n-1; i >= 0; --i){
        suffix_sum += indices[i];
        res[indices[i]] += abs((prefix_sum[i] - (long long)i * indices[i]) + ((long long)(n-i-1) * indices[i] - suffix_sum));
      }
    }
    return res;
  }
};