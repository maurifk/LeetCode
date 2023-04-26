#include "semaphore.h"
#include <functional>
using namespace std;

class FooBar{
private:
  int n;
  sem_t S1;
  sem_t S2;

public:
  FooBar(int n){
    this->n = n;
    sem_init(&S1, 0, 1);
    sem_init(&S2, 0, 0);
  }

  void foo(function<void()> printFoo){
    for (int i = 0; i < n; i++){
      sem_wait(&S1);
      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();
      sem_post(&S2);
    }
  }

  void bar(function<void()> printBar){
    for (int i = 0; i < n; i++){
      sem_wait(&S2);
      // printBar() outputs "bar". Do not change or remove this line.
      printBar();
      sem_post(&S1);
    }
  }
};