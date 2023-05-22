#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> pila;
    int a,b;

    for (string token : tokens){
      if (token == "+" || token == "-" || token == "*" || token == "/") {
        b = pila.top();
        pila.pop();
        a = pila.top();
        pila.pop();

        int res;
        if(token == "+"){
          res = a+b;
        } else if (token == "-"){
          res = a-b;
        }  else if (token == "*"){
          res = a*b;
        } else {
          res = (int)a/b;
        }

        pila.push(res);
      } else {
        pila.push(stoi(token));
      }
    }

    return pila.top();
  }
}; 