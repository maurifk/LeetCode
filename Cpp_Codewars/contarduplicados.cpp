#include <string>
#include <set>
using namespace std;

size_t duplicateCount(const string& in); // helper for tests

size_t duplicateCount(const char* in){ // Pa que char* ??
  set<char> letras;
  set<char> dupl;

  string ins(in);

  for (int i = 0; i<ins.size(); ++i){
    if((ins[i] >= 'a') && (ins[i]<='z')){
      if (letras.count(ins[i])){
        dupl.insert(ins[i]);
      } else {
        letras.insert(ins[i]);
      }
    } else if ((ins[i] >= 'A') && (ins[i]<='Z')){
      if (letras.count((char)(ins[i]-'A'+'a'))){
        dupl.insert((char)(ins[i]-'A'+'a'));
      } else {
        letras.insert((char)(ins[i]-'A'+'a'));
      }
    } else if ((ins[i] >= '0') && (ins[i]<='9')){
      if (letras.count(ins[i])){
        dupl.insert(ins[i]);
      } else {
        letras.insert(ins[i]);
      }
    }
  }

  return dupl.size();
}
