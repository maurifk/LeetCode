#include <cmath>
using namespace std;

bool narcissistic( int value ){
  int accum = 0, i = 0, val = value;

  while (val != 0){
    val = val / 10;
    i++;
  }

  val = value;

  for (int j = 1; j<=i; ++j){
    accum += pow(val % 10, i);
    val /= 10;
  }

  return (accum == value);
}