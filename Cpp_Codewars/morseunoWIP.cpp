// https://www.codewars.com/kata/54b724efac3d5402db00065e
#include <string>
using namespace std;

string decodeMorse(string morseCode) {
  // ToDo: Accept dots, dashes and spaces, return human-readable message
  string decoded = "", letra = "";
  int comienzo = 0, i = 0;
  bool fin = false;

  while(morseCode[comienzo] == ' '){
    comienzo++;
  }

  while(!fin){
    while(morseCode[comienzo+i] != ' '){ // Chupar letra
      letra += morseCode[comienzo+i];
      i++;
    }
    comienzo += i + 1;
    i = 0;
    decoded += MORSE_CODE[letra];
    letra.clear();

    if (morseCode.size() <= comienzo){
      fin = true;
      break;
    }

    if(morseCode[comienzo] == ' '){
      decoded += ' ';
      comienzo += 2;
      if (morseCode.size() <= comienzo){
        fin = true;
        decoded.pop_back();
        break;
      }
      if(morseCode[comienzo] == ' '){
        fin = true;
        decoded.pop_back();
        break;
      }
    }
  }

  return decoded;
}