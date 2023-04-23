#include <vector>
#include <algorithm>
using namespace std;


// TLE : Works for unbounded nums[i] -> O(n^2)
class Solution {
public:
  // b siempre esta en vec
  int busqBin(vector<int>& vec, int b){
    int izq = 0;
    int der = vec.size()-1;
    int med;
    if(vec[der] == b) return der;
    if(vec[0] == b) return 0;
    
    while(izq<=der){
      med = (izq+der)/2;
      if(vec[med] == b){
        return med;
      } else if(vec[med] < b){
        izq = med+1;
      } else {
        der = med-1;
      }
    }
    return izq;
  }

  void pisarOrdenado(vector<int>& vec, int aPisar, int nuevo){
    int i = busqBin(vec, aPisar);
    
    vec[i] = nuevo;
    
    if(i<vec.size()-1 && vec[i+1] < nuevo){
      while(i < vec.size()-1 && vec[i+1] < nuevo){
        swap(vec[i], vec[i+1]);
        i++;
      }
    } else if (i>0 && vec[i-1] > nuevo){
      while(i>0 && vec[i-1] > nuevo){
        swap(vec[i], vec[i-1]);
        i--;
      }
    }
  }

  vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    vector<int> res (nums.size()-k+1);
    vector<int> subv (nums.begin(), nums.begin()+k);
    sort(subv.begin(), subv.end());
    res[0] = min(0, subv[x-1]);

    for(int i = 1; i+k<=nums.size(); i++){
      pisarOrdenado(subv, nums[i-1], nums[i+k-1]);
      res[i] = min(0, subv[x-1]);
    }
    
    return res;
  }
};