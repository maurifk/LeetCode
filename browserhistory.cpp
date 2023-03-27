#include <string>
#include <stack>
using namespace std;


class BrowserHistory {
public:
  stack<string> historialAtras;
  stack<string> historialAdelante;
  string actual; 

  BrowserHistory(string homepage) {
    actual = homepage;
  }
  
  void visit(string url) {
    while(!historialAdelante.empty()){
      historialAdelante.pop();
    }
    historialAtras.push(actual);
    actual = url;
  }

  void unoAtras(){
    if(!historialAtras.empty()){
      historialAdelante.push(actual);
      actual = historialAtras.top();
      historialAtras.pop();
    }
  }
    
  string back(int steps) {
    for(int i = 1; i<= steps; ++i){
      unoAtras();
    }
    return actual;
  }

  void unoAdelante(){
    if(!historialAdelante.empty()){
      historialAtras.push(actual);
      actual = historialAdelante.top();
      historialAdelante.pop();
    }
  }

  string forward(int steps) {
    for(int i = 1; i<= steps; ++i){
      unoAdelante();
    }
    return actual;
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * string param_2 = obj.back(steps);
 * string param_3 = obj.forward(steps);
 */