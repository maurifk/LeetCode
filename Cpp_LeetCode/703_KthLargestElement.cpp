#include <vector>
#include <queue>
using namespace std;

class KthLargest {
private:
  priority_queue<int, vector<int>, greater<int> > pq;
  int k;

public:
  KthLargest(int k, vector<int>& nums) {
    this->k = k;
    int n = nums.size();

    for(int i = 0; i<n; ++i){
      pq.push(nums[i]);
    }
  }

  int add(int val) {
    pq.push(val);


    while(pq.size()>k){
      pq.pop();
    }

    int res = pq.top();
    return res;
  }
};
