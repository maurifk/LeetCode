#include <cctype>
#include <string>
using namespace std;

bool XO(const string& str)
{
  int equisyos[2]; // [0] == cant 'X'
  equisyos[0] = 0;
  equisyos[1] = 0;

  for (int i = 0; i<str.size(); ++i){
    if((char)(tolower(str[i])) == 'x'){
      equisyos[0]++;
    } else if ((char)(tolower(str[i])) == 'o'){
      equisyos[1]++;
    }
  }

  return (equisyos[0] == equisyos[1]);
}