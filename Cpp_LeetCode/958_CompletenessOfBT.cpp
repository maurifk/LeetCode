#include <vector>
#include <queue>
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
  bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> cola;
    if (!root) return true;

    cola.push(root);
    while (cola.front() != nullptr){
      TreeNode* temp = cola.front();
      cola.pop();
      cola.push(temp->left);
      cola.push(temp->right);
    }

    while (!cola.empty() && cola.front() == nullptr){
      cola.pop();
    }

    return cola.empty();
  }
};