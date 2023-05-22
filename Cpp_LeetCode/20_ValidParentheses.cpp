#include <string>
#include <stack>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> pila;
    bool valido = true;

    for(int i = 0; i<s.length() && valido; ++i){
      switch (s[i])
      {
      case '(':
      case '[':
      case '{':
        pila.push(s[i]);
        break;
        
      case ')':
        if(!pila.empty() && pila.top() == '('){
          pila.pop();
        } else {
          valido = false;
        }
        break;

      case ']':
        if(!pila.empty() && pila.top() == '['){
          pila.pop();
        } else {
          valido = false;
        }
        break;

      case '}':
        if(!pila.empty() && pila.top() == '{'){
          pila.pop();
        } else {
          valido = false;
        }
        break;
      }
    }

    return valido && pila.empty();
  }
};