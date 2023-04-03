#include <bitset>
#include <vector>
using namespace std;

class Solution {
public:
  void cambiarDos(string& s, int i1, int i2){
    int temp = s[i1];
    s[i1] = s[i2];
    s[i2] = temp;
  }

  void reverseString(string& s) {
    int i1 = 0, i2 = s.size()-1;
    while(i1<i2){
      cambiarDos(s, i1, i2);
      i1++;
      i2--;
    }
  }

  uint32_t reverseBits(uint32_t n) {
    bitset<32> b(n);
    string bs = b.to_string();
    reverseString(bs);

    bitset<32> br(bs);
    return br.to_ulong();
  }
};