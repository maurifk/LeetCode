#include <vector>
#include <unordered_set>
using namespace std;

// Fails

class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size(), act = 0;
    vector<int> res(n);
    unordered_set<int> enA;
    unordered_set<int> enB;
    for (int i = 0; i < n; i++) {
      enA.insert(A[i]);
      enB.insert(B[i]);
      if (A[i] == B[i]){
        act++;
      } else{
        if (enA.find(B[i]) != enA.end()) {
          act++;
        }
        if (enB.find(A[i]) != enB.end()) {
          act++;
        }
      }
      res[i] = act;
    }
    return res;
  }
};
