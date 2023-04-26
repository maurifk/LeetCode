#include "semaphore.h"
#include "pthread.h"
#include <functional>
using namespace std;

class H2O{
private:
  pthread_barrier_t b;
  sem_t SH;
  sem_t SO;

public:
  H2O(){
    pthread_barrier_init(&b, 0, 3);
    sem_init(&SH, 0, 2);
    sem_init(&SO, 0, 1);
  }

  void hydrogen(function<void()> releaseHydrogen){
    sem_wait(&SH);
    pthread_barrier_wait(&b);
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseHydrogen();
    sem_post(&SH);
  }

  void oxygen(function<void()> releaseOxygen){
    sem_wait(&SO);
    pthread_barrier_wait(&b);
    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseOxygen();
    sem_post(&SO);
  }
};