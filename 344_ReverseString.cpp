#include <vector>
using namespace std;

class Solution {
public:
  void cambiarDos(vector<char>& s, int i1, int i2){
    int temp = s[i1];
    s[i1] = s[i2];
    s[i2] = temp;
  }

  void reverseString(vector<char>& s) {
    int i1 = 0, i2 = s.size()-1;
    while(i1<i2){
      cambiarDos(s, i1, i2);
      i1++;
      i2--;
    }
  }
};