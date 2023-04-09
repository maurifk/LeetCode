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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty() || postorder.empty()) {
      return nullptr;
    }
    int root_val = postorder.back();
    TreeNode* root = new TreeNode(root_val);
    int rooti = 0;
    while (inorder[rooti] != root_val) {
      ++rooti;
    }
    vector<int> izq_inorder(inorder.begin(), inorder.begin() + rooti);
    vector<int> der_inorder(inorder.begin() + rooti + 1, inorder.end());
    vector<int> izq_postorder(postorder.begin(), postorder.begin() + rooti);
    vector<int> der_postorder(postorder.begin() + rooti, postorder.end() - 1);
    root->left = buildTree(izq_inorder, izq_postorder);
    root->right = buildTree(der_inorder, der_postorder);
    return root;
  }
};