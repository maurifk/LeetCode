#include <queue>
using namespace std;

class SmallestInfiniteSet {
private:
  int smallest;
  priority_queue <int, vector<int>, greater<int>> cola;

public:
  SmallestInfiniteSet() {
    smallest = 1;
  }
    
  int popSmallest() {
    if (cola.empty()) {
      smallest++;
      return smallest - 1;

    } else {
      int tope = cola.top();
      cola.pop();
      while (!cola.empty() && tope == cola.top()) {
        cola.pop();
      }
      return tope;
    }
  }
    
  void addBack(int num) {
    if(num < smallest){
      if (num == smallest - 1) {
        smallest--;
      } else {
        cola.emplace(num);
      }
    }
  }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */