#include <string>
#include <set>
using namespace std;

int getCount(const string& inputStr){
  int num_vowels = 0;
  set<char> vocales = {'a','e','i','o','u','A','E','I','O','U'};
  
  for (int i = 0; i<inputStr.length(); ++i){
    if (vocales.count(inputStr[i])){
      num_vowels++;
    } 
  }

  return num_vowels;
}