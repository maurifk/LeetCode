#include <iostream>
#include <cmath>
using namespace std;

int digital_root(int n){
  if (n / 10 == 0) return n;
  int digs = floor(log10(n)) + 1;
  int acum = 0;

  for (int i = 1; i<=digs; ++i){
    acum += n % 10;
    n /= 10;
  }
  
  return (floor(log10(acum)) + 1 == 1) ? acum : digital_root(acum);
}

int main(){
  cout<<digital_root(1213213);
}