#include "semaphore.h"
#include <functional>
using namespace std;

class FizzBuzz{
private:
  int n;
  sem_t sfizz;
  sem_t sbuzz;
  sem_t sfizzbuzz;
  sem_t snum;

public:
  FizzBuzz(int n){
    this->n = n;
    sem_init(&sfizz, 0, 0);
    sem_init(&sbuzz, 0, 0);
    sem_init(&sfizzbuzz, 0, 0);
    sem_init(&snum, 0, 1);
  }

  // printFizz() outputs "fizz".
  void fizz(function<void()> printFizz){
    for (int i = 1; i <= n; ++i){
      if (i % 5 != 0 && i % 3 == 0){
        sem_wait(&sfizz);
        printFizz();
        soltador(i + 1);
      }
    }
  }

  // printBuzz() outputs "buzz".
  void buzz(function<void()> printBuzz){
    for (int i = 1; i <= n; ++i){
      if (i % 5 == 0 && i % 3 != 0){
        sem_wait(&sbuzz);
        printBuzz();
        soltador(i + 1);
      }
    }
  }

  // printFizzBuzz() outputs "fizzbuzz".
  void fizzbuzz(function<void()> printFizzBuzz){
    for (int i = 1; i <= n; ++i){
      if (i % 5 == 0 && i % 3 == 0){
        sem_wait(&sfizzbuzz);
        printFizzBuzz();
        soltador(i + 1);
      }
    }
  }

  // printNumber(x) outputs "x", where x is an integer.
  void number(function<void(int)> printNumber){
    for (int i = 1; i <= n; ++i){
      if (i % 3 != 0 && i % 5 != 0){
        sem_wait(&snum);
        printNumber(i);
        soltador(i + 1);
      }
    }
  }

  void soltador(int i){
    if (i % 15 == 0){
      sem_post(&sfizzbuzz);
    } else if (i % 5 == 0) {
      sem_post(&sbuzz);
    } else if (i % 3 == 0) {
      sem_post(&sfizz);
    } else {
      sem_post(&snum);
    }
  }
};