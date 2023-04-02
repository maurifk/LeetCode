#include <vector>
using namespace std;

class Solution {
public:
  void auxC(vector<vector<int>>& res, vector<int>& temp, int i, int n, int k){
    if (temp.size() == k){
      res.push_back(temp);
      return;
    }

    for (int j = i; j<=n; ++j){
      temp.push_back(j);
      auxC(res, temp, i+1, n, k);
      temp.pop_back();
    }
  }

  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> pseudores;
    auxC(res,pseudores,1,n,k);
    return res;
  }
};