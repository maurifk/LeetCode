#include <string>
#include <regex>
using namespace std;

class Solution {
public:
  string defangIPaddr(string address) {
    regex re("\\.");
    string result = regex_replace(address, re, "[.]");
    return result;
  }
};
