#include "semaphore.h"
#include <functional>
using namespace std;

class ZeroEvenOdd{
private:
  int n;
  sem_t SZeros;
  sem_t SImpar;
  sem_t SPar;

public:
  ZeroEvenOdd(int n){
    this->n = n;
    sem_init(&SZeros, 0, 1);
    sem_init(&SImpar, 0, 0);
    sem_init(&SPar, 0, 0);
  }

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber){
    for (int i = 1; i <= n; ++i){
      sem_wait(&SZeros);
      printNumber(0);
      if (i % 2 == 0){
        sem_post(&SPar);
      } else {
        sem_post(&SImpar);
      }
    }
  }

  void even(function<void(int)> printNumber){
    for (int i = 2; i <= n; i += 2){
      sem_wait(&SPar);
      printNumber(i);
      sem_post(&SZeros);
    }
  }

  void odd(function<void(int)> printNumber){
    for (int i = 1; i <= n; i += 2){
      sem_wait(&SImpar);
      printNumber(i);
      sem_post(&SZeros);
    }
  }
};