#include <string>
using namespace std;

bool solution(string const &str, string const &ending) {
  for (int i = 0; i<ending.length(); ++i){
    if (str[str.length()-1-i] != ending[ending.length()-1-i]) return false;
  }
  return true;
}