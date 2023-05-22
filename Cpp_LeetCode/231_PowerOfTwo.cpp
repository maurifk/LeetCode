#include <bitset>
using namespace std;

class Solution {
public:
  bool isPowerOfTwo(int n) {
    bitset<32> b(n);
    return n>0 && b.count() <= 1;
  }
};