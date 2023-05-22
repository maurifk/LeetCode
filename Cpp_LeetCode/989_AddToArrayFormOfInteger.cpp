#include <vector>
using namespace std;

class Solution {
public:
  vector<int> addToArrayForm(vector<int>& num, int k) {
    int carry = 0, i = num.size()-1;
    do {
      if (i>=0){
        int a = num[i];
        if(i == num.size()-1) a+=k;
        a += carry;
        if(a>9){
          carry = (int) a/10;
          a = a % 10;
        } else {
          carry = 0;
        }
        num[i] = a;
        i--;
      } else {
        num.insert(num.begin(), carry%10);
        carry /= 10;
      }
    } while (carry != 0);
    return num;
  }
};