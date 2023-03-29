#include <string>
using namespace std;

string cerdoAux(string& s, int base, int largo){
  string res = "";
  if(!(s[base]-'a'>=0) || !(s[base]-'a'<=25)) return res + s[base];
  res = s.substr(base+1,largo-1);
  res += s[base];
  res += "ay";

  return res;
}

string cerdificar(string s) {
  string t = "";

  int i1 = 0, i2 = 1;
  while (i2 < s.length()){
    while (s[i2] - 'a' >= 0 && s[i2] - 'a' <= 25){
      i2++;
      if (i2 >= s.length()) break;
    }

    t += cerdoAux(s, i1, i2-i1-1);

    i1 = i2;

    while (i1 < s.length() && !((s[i1]>=0)&&(s[i1]<=25))){
      t += s[i1];
    }

    i2= i1+1;
  }
  t += cerdoAux(s, i1, i2-i1-1);
  return t;
}

string pig_it(string str){
  return cerdificar(str);
}