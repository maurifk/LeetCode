#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool vectoresIguales(vector<int> vecuno, vector<int> vecdos){
    for (int i = 0; i<26; ++i){
      if(vecuno[i] != vecdos[i]) return false;
    }
    return true;
  }

  bool checkInclusion(string s1, string s2) {
    int prin = 0, fin = 0;
    vector<int> freqinc(26, 0);
    vector<int> freqvent(26, 0);

    if (s1.length() > s2.length()) return false;

    for (char c : s1) freqinc[c-'a']++;

    while (fin<s2.size()){
      freqvent[s2[fin]-'a']++;

      if (fin-prin + 1 == s1.size()){
        if (vectoresIguales(freqinc,freqvent)) return true;;
      }
      if (fin-prin+1 < s1.size()) fin++;
      else {
        freqvent[s2[prin]-'a']--;
        prin++;
        fin++;
      }
    }

    return false;
  }
};