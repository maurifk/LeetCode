#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  /*
  vector<int> mergeListas(vector<int>& nums1, vector<int>& nums2){
    int puntuno = 0, puntdos = 0;
    vector<int> res;
    do{
      if((puntuno < nums1.size()) && (puntdos < nums2.size())){
        int uno = nums1[puntuno], dos = nums2[puntdos]; 
        res.push_back(uno < dos ? uno : dos);
        if (uno < dos){
          puntuno++;
        } else {
          puntdos++;
        }
      } else if (puntuno < nums1.size()){
        for (int i = puntuno; i < nums1.size(); ++i){
          res.push_back(nums1[i]);
        }
        puntuno = nums1.size();
      } else {
        for (int i = puntdos; i < nums2.size(); ++i){
          res.push_back(nums2[i]);
        }
        puntdos = nums2.size();
      }
    } while ((puntuno < nums1.size()) || (puntdos < nums2.size()));

    return res;
  }
  */
  

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    /*
    int n = nums1.size(), m = nums2.size();
    vector<int> v;
    for (int i = 0; i<n; ++i){
      v.push_back(nums1[i]);
    }

    for (int i = 0; i<m; ++i){
      v.push_back(nums2[i]);
    }

    sort(v.begin(), v.end());
    n = v.size();
    */

    vector<int> v(nums1.size() + nums2.size());
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), v.begin());
    int n = v.size();

    if (n % 2 == 1){
      return v[(n + 1)/2-1];
    } else {
      return ((v[n/2-1] + v[n/2]) / 2.0);
    }
  }
};