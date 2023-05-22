#include <string>
using namespace std;

string alphabet_position(const string &text) {
  string res = "";

  for (int i = 0; i<text.length(); ++i){
    if (text[i] >= 'a' && text[i] <= 'z') {
      res = res +  to_string(text[i]-'a' +1) + ' ';
    } else if (text[i] >= 'A' && text[i] <= 'Z'){
      res = res +  to_string(text[i]-'A' +1) + ' ';
    }
  }

  if (!res.empty()) res.pop_back();

  return res;
}