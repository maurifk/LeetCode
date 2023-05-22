#include <string>
using namespace std;

class WordDictionary {
public:
  class Nodo{
    public:

    Nodo* Hijos[27];
    bool final;
    char letra;

    Nodo(char letra){
      for (int i = 0; i<27; ++i){
        Hijos[i] = nullptr;
      }
      final = false;
      this->letra = letra;
    }
    void setFin(){
      final = true;
    }
  };
  Nodo* nodo;

  WordDictionary() {
    nodo = new Nodo('~');
  }
  
  void addWord(string word) {
    Nodo* t = this->nodo;
    for (int i = 0; i<word.size(); ++i){
      if (t->Hijos[word[i]-'a'] == nullptr){
        t->Hijos[word[i]-'a'] = new Nodo(word[i]);
        t->Hijos[26] = t;
      }
      t = t->Hijos[word[i]-'a'];
    }
    t->setFin();
  }
  
  bool searchAux(string word, Nodo* t){
    if (t == nullptr) return false;

    for (int i = 0; i<word.size(); ++i){
      if(word[i] == '.'){
        if (t->Hijos[26] == nullptr) return false; 
        for(int j = 0; j<26; ++j){
          bool aux = searchAux(word.substr(i+1, string::npos), t->Hijos[j]);
          if(aux) return true;
        }
        return false;
      } else {
        if (t->Hijos[word[i]-'a'] == nullptr){
          return false;
        }
        t = t->Hijos[word[i]-'a'];
      }
    }
    return t->final;
  }

  bool search(string word) {
    Nodo* t = this->nodo;
    for (int i = 0; i<word.size(); ++i){
      if(word[i] == '.'){
        if (t->Hijos[26] == nullptr) return false;
        for(int j = 0; j<26; ++j){
          bool aux = searchAux(word.substr(i+1, string::npos), t->Hijos[j]);
          if(aux) return true;
        }
        return false;
      } else {
        if (t->Hijos[word[i]-'a'] == nullptr){
          return false;
        }
        t = t->Hijos[word[i]-'a'];
      }
    }
    return t->final;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */