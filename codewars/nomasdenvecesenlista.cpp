#include <vector>
#include <set>
using namespace std;

vector<int> deleteNth(vector<int> arr, int n){
  multiset<int> nums;
  vector<int> res;

  for(int i = 0; i<arr.size(); ++i){
    if (nums.count(arr[i]) < n){
      res.push_back(arr[i]);
      nums.insert(arr[i]);
    }
  }
  return res;;
}