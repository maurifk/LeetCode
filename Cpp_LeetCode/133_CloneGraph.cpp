#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  Node* DFS(Node* act, unordered_map<int,Node*>& mapa){
    vector<Node*> vecinos;
    Node* copia = new Node(act->val);
    mapa[act->val] = copia;
    for (auto iter : act->neighbors){
      if(mapa.find(iter->val) != mapa.end()){
        vecinos.push_back(mapa[iter->val]);
      } else {
        vecinos.push_back(DFS(iter, mapa));
      }
    }
    copia->neighbors = vecinos;
    return copia;    
  }

  Node* cloneGraph(Node* node) {
    unordered_map<int, Node*> mapa;
    if (node == nullptr) return nullptr;
    if (node->neighbors.size() == 0){
      Node* copia = new Node(node->val);
      return copia;
    }

    return DFS(node, mapa);
  }
};