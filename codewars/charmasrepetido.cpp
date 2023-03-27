#include <utility>
#include <string>
#include <optional>
#include <unordered_map>

using namespace std;

optional<pair<char, unsigned int>> longestRepetition(const string &str) {
  unordered_map<char,pair<int,int>> map; // {char letra, {int indiceUlt, int veces}}
  pair<int,int> aux;

  for (unsigned int i = 0; i<str.size(); ++i){
    if(map.count(str[i])){
      if (map[str[i]].first == i-1){
        map[str[i]] = {i, map[str[i]].second+1};
      } else {
        if(str[i-1] != str[i]){
          aux = {i,1};
        } else {
          aux = {i,aux.second+1};
          if (map[str[i]].second < aux.second){
            map[str[i]] = aux;
          }
        }
      }
    } else {
      aux = {i,1};
      map[str[i]] = aux;
    }
  }
  
  if (!str.size()) return nullopt;
  
  pair<char,pair<int,int>> maxi = {'~',{0,0}};

  for(pair<char,pair<int,int>> it : map){
    if(it.second.second > maxi.second.second){
      maxi = it;
    } else if (it.second.second == maxi.second.second){
      if (it.second.first < maxi.second.first){
        maxi = it;
      }
    }
  }

  return make_pair(maxi.first, maxi.second.second);
}