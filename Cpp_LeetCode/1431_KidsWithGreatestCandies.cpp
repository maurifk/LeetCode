#include <vector>
using namespace std;

class Solution {
public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maxcarams = *max_element(candies.begin(), candies.end());
    vector<bool> res (candies.size(), false);

    for (int i = 0; i<candies.size(); ++i){
      res[i] = candies[i]+extraCandies >= maxcarams;
    }

    return res;
  }
};