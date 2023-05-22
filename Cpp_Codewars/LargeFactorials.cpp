#include <vector>
#include <string>
using namespace std;

int mult(int x, vector<int> &res, int ress)
{
  int c = 0;

  for (int i = 0; i < ress; i++) {
    int prod = res[i] * x + c;

    res[i] = prod % 10;

    c = prod / 10;
  }

  while (c) {
    res.push_back(c % 10);
    c = c / 10;
    ress++;
  }

  return ress;
}

string factorial(int n){
  if(n<0) return "";

  vector<int> resu = {1};
  int rtam = 1;

  for(int i = 2; i<=n; ++i){
    rtam = mult(i, resu, rtam);
  }

  string sres = "";

  for (int i = rtam-1; i>=0; --i){
    sres += to_string(resu[i]);
  }

  return sres;

}
