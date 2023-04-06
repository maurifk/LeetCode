#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<long long> pila;
    long long a,b;

    for (int i = 0; i<tokens.size(); ++i){
      if (tokens[i][0] >= '0' && tokens[i][0] <= '9'){
        pila.push(tokens[i][0] - '0');
      } else {
        char oper = tokens[i][0];
        switch (oper)
        {
        case '+':
          b = pila.top();
          pila.pop();
          a = pila.top(); 
          pila.pop();
          pila.push(a+b);
          break;

        case '-':
          b = pila.top();
          pila.pop();
          a = pila.top(); 
          pila.pop();
          pila.push(a-b);
          break;

        case '*':
          b = pila.top();
          pila.pop();
          a = pila.top(); 
          pila.pop();
          pila.push(a*b);
          break;

        default:
          b = pila.top();
          pila.pop();
          a = pila.top(); 
          pila.pop();
          pila.push((long long)(a/b));
          break;
        }
      }
    }
    return pila.top();
  }
};