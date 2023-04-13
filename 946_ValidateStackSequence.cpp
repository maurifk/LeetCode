#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> pila;
    int popeados = 0;

    for(int i = 0; i<pushed.size(); ++i){
      pila.push(pushed[i]);
      while(!pila.empty() && pila.top() == popped[popeados]){
        ++popeados;
        pila.pop();
      }
    }
    return popeados == popped.size();
  }
};