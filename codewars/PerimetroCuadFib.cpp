#include <vector>
using namespace std;

typedef unsigned long long ull;

class SumFct{
public:
  static ull perimeter(int n);
}; 


ull SumFct::perimeter(int n) {
  //FIB
  vector<int> fib(n+1);
  fib[0] = 1;
  fib[1] = 1;
  ull acum = 2;

  for(int i = 2; i<n+1; ++i){
    fib[i] = fib[i-1]+fib[i-2];
    acum += fib[i];
  }

  return acum * 4; 
}
