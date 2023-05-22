#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
  double average(vector<int>& salary) {
    sort(salary.begin(), salary.end());
    int sum = accumulate(salary.begin()+1, salary.end()-1, 0);
    return sum / (salary.size()-2);
  }
};
