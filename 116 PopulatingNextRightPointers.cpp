#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node* connect(Node* root) {
    if(!root) return nullptr;
    queue<Node*> cola;
    cola.push(root);

    while(!cola.empty()){
      Node* nodoDer = nullptr;
      for(int i = cola.size(); i; --i){ // ???
        Node* act = cola.front();
        cola.pop();

        act->next = nodoDer;
        nodoDer = act;
        if(act->right){
          cola.push(act->right);
          cola.push(act->left);
        }
      }
    }
    return root;
  }
};