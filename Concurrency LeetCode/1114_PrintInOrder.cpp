#include "semaphore.h"
#include <functional>
using namespace std;

class Foo {
private:
  int cont;
  sem_t S;

public:
  Foo() {
    cont = 1;
    sem_init(&S, 0, 1);
  }

  void first(function<void()> printFirst) {
    sem_wait(&S);

    cont++;
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    sem_post(&S);
  }

  void second(function<void()> printSecond) {
    sem_wait(&S);
    while (cont != 2){
      sem_post(&S);
      sem_wait(&S);
    }
    cont++;
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    sem_post(&S);
  }

  void third(function<void()> printThird) {
    sem_wait(&S);
    while (cont != 3){
      sem_post(&S);
      sem_wait(&S);
    }
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};