#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    string resul = "";
    int c = 0, dig1, dig2;
  
    if (num1 == "0" || num2 == "0"){
      return "0";
    }

    int n1 = num1.length(), n2 = num2.length();
    int indn1 = 0, indn2 = 0;

    vector<int> result (n1+n2, 0);

    for(int i1 = n1-1; i1>=0; --i1){
      c = 0;
      dig1 = num1[i1] - '0';
      indn2 = 0;

      for (int i2 = n2-1; i2>=0; --i2){
        dig2 = num2[i2] - '0';
        int prod = dig1*dig2 + result[indn1 + indn2] + c;
        c = prod / 10;
        result[indn1+indn2] = prod % 10;

        indn2++;
      }
      if (c>0) result[indn1+indn2] += c;
      indn1++;
    }

    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0) {
      i--;
    }

    if (i == -1) {
      return "0";
    }

    string res = "";
    while (i >= 0) {
      res += to_string(result[i]);
      i--;
    }

    return res;
  }
};