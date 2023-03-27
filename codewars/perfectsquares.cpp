#include <cmath>

long int findNextSquare(long int sq) {

  // Return the next square if sq if a perfect square, -1 otherwise
  double raiz = sqrt(sq); 
  if(trunc(raiz) != raiz) return -1;

  return pow(trunc(raiz) + 1, 2);
}