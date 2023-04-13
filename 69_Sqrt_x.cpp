class Solution {
public:
  // Binary Search should be used
  int mySqrt(int x) {
    int i = 0;
    while(i*(i++) <= x){}

    return i;
  }
};