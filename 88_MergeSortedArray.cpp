#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int uno = 0, dos = 0;
    stack<int> s;
    while(uno<m || dos<n){
      if (uno<m && dos<n){
        if (nums1[uno]<nums2[dos]){
          s.push(nums1[uno++]);
        } else {
          s.push(nums2[dos++]);
        }
      } else if (uno<m){
        s.push(nums1[uno++]);
      } else {
        s.push(nums2[dos++]);
      }
    }

    int i = n+m-1;
    while (!s.empty()){
      nums1[i--] = s.top();
      s.pop();
    }
  }
};
