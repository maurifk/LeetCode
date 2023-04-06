#include <vector>
using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    int carry = 0, i = digits.size()-1;
    do {
      if (i>=0){
        int a = digits[i];
        if(i == digits.size()-1) a++;
        a += carry;
        if(a>9){
          carry = (int) a/10;
          a = a % 10;
        } else {
          carry = 0;
        }
        digits[i] = a;
        i--;
      } else {
        digits.insert(digits.begin(), carry);
        carry = 0;
      }
    } while (carry != 0);
    return digits;
  }
};