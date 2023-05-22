#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    int al = a.length(), bl = b.length();
    int dif = al-bl;

    while (dif != 0){
      if (dif<0){
        a = '0' + a;
        dif++;
      } else{
        b = '0' + b;
        dif--;
      }
    }

    vector<int> res(a.length()+1,'0');

    int c = 0;
    for(int i = a.length()-1; i>=0; --i){
      int diga = a[i]-'0', digb = b[i] - '0';
      int suma = diga+digb+c;
      res[i+1] = suma % 2;
      c = (int)(suma / 2);
    }
    res[0] = c;
    int i = 0;
    while (i<res.size() && res[i] == 0){
      i++;
    }
    
    if(i == res.size()) return "0";

    string resS = "";
    while(i<res.size()){
      resS = resS + to_string(res[i]);
      i++;
    }

    return resS;
  }
};