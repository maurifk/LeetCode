#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // O(n^2)
  int numberOfArrays(string s, int k) {
    int n = s.length();
    int MOD = 1e9 + 7;
    vector<long long> OPT (n+1, 0);
    for (int i = 1; i<=n; ++i){
      for (int j = 0; j < i; ++j){
        if (s[j] == '0') continue;
        int num = stoi(s.substr(j, i-j+1));
        if (num >= 1 && num <= k) OPT[i] += OPT[j];
      }
    }
    return OPT[n] % MOD;
  }
};

