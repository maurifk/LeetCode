#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  void esavlyprof(TreeNode* abb, bool &avl, unsigned int &prof){
    bool avlizq, avlder;
    unsigned int profizq, profder;
    if (abb != nullptr){
      esavlyprof(abb->left, avlizq, profizq);
      esavlyprof(abb->right, avlder, profder);

      avl = avlder && avlizq && ((profizq == profder) || (profder == 1 + profizq) || (profizq == 1 + profder));
      //avl = avlder && avlizq && (diferencia(profizq, profder) <= 1);
      prof = 1 + max(profizq, profder);
    
    } else {
      avl = true;
      prof = 0;
    }
  }
  bool isBalanced(TreeNode* root) {
    bool avl = true;
    unsigned int prof = 0;
    esavlyprof(root, avl, prof);
    return avl; 
  }
};