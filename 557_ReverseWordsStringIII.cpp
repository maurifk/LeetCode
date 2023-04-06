#include <string>
using namespace std;

class Solution {
public:

    void cambiarDos(string& s, int i1, int i2, int base){
      int temp = s[base+i1];
      s[base+i1] = s[base+i2];
      s[base+i2] = temp;
    }

    void reverseString(string& s, int base, int largo) {
        int i1 = 0, i2 = largo;
        while(i1<i2){
          cambiarDos(s, i1, i2, base);
          i1++;
          i2--;
        }
    }

    string reverseWords(string s) {
        string t = "generico";
        t = s;
        int i1 = 0, i2 = 1;
        while (i2 < t.length()){
            while (t[i2] != ' '){
                i2++;
                if (i2 >= t.length()) break;
            }
            
            reverseString(t, i1, i2-i1-1);

            i1=i2;
            i1++;
            i2+=2;
        }
        reverseString(t, i1, i2-i1-1);
        return t;
    }
};