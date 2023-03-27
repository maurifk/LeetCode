#include <string>
using namespace std;

class Trie {
public:
  class Nodo{
    public:

    Nodo* Hijos[26];
    bool final;
    char letra;

    Nodo(char letra){
      for (int i = 0; i<26; ++i){
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

  Trie() {
    nodo = new Nodo('~');
  }
    
  void insert(string word) {
    Nodo* t = this->nodo;
    for (int i = 0; i<word.size(); ++i){
      if (t->Hijos[word[i]-'a'] == nullptr){
        t->Hijos[word[i]-'a'] = new Nodo(word[i]);
      }
      t = t->Hijos[word[i]-'a'];
    }
    t->setFin();
  }
  
  bool search(string word) {
    Nodo* t = this->nodo;
    for (int i = 0; i<word.size(); ++i){
      if (t->Hijos[word[i]-'a'] == nullptr){
        return false;
      }
      t = t->Hijos[word[i]-'a'];
    }
    return t->final;
  }
    
  bool startsWith(string prefix) {
    Nodo* t = this->nodo;
    for (int i = 0; i<prefix.size(); ++i){
      if (t->Hijos[prefix[i]-'a'] == nullptr){
        return false;
      }
      t = t->Hijos[prefix[i]-'a'];
    }
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */