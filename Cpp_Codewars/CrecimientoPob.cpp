#include <cmath>

class Arge
{
  public:
  static int nbYear(int p0, double percent, int aug, int p);
};

int Arge::nbYear(int p0, double percent, int aug, int p){
  int pob = p0;
  int i = 0;
  while (pob<p){
    i++;
    pob = trunc(pob + pob*(percent/100) + aug);
  }
  return i;
}