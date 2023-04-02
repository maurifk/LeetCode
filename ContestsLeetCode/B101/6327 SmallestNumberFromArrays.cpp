#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int minNumber(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> map1;
    int min1 = 10, min2 = 10, minrep = 10;

    for (int i = 0; i<nums1.size(); ++i){
      min1 = min(min1,nums1[i]);
      map1[nums1[i]] = i;
    }

    for (int i = 0; i<nums2.size(); ++i){
      min2 = min(min2,nums2[i]);
      if (map1.count(nums2[i])){
        minrep = min(minrep,nums2[i]);
      }
    }

    if (minrep != 10) return minrep;

    if(min1 < min2){
      return min1*10 + min2;
    } else {
      return min2*10 + min1;
    }
  }
};