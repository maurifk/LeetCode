#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> res;
    vector<int> nums3 (nums1.begin(), nums1.end());
    vector<int> nums4 (nums2.begin(), nums2.end());
    sort(nums3.begin(), nums3.end());
    sort(nums4.begin(), nums4.end());

    vector<int>::iterator it1;
    vector<int>::iterator it2;
    it1 = unique(nums3.begin(), nums3.end());
    it2 = unique(nums4.begin(), nums4.end());

    nums3.resize(distance(nums3.begin(),it1));
    nums4.resize(distance(nums4.begin(),it2));

    vector<int> v1;
    vector<int> v2;
    set_difference(nums3.begin(), nums3.end(), nums4.begin(), nums4.end(), inserter(v1, end(v1)));
    set_difference(nums4.begin(), nums4.end(), nums3.begin(), nums3.end(), inserter(v2, end(v2)));
    res.push_back(v1);
    res.push_back(v2);
    return res;
  }
};
