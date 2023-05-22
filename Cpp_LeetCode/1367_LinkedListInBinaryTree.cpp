
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
  bool auxSubCamino(ListNode* head, TreeNode* root, ListNode* act, TreeNode* back){
    if(act == nullptr) return true;
    if(root == nullptr) return false;

    if(act->val == root->val){
      if(head == act){
        return(auxSubCamino(head, root->left, act->next, root->left) || auxSubCamino(head, root->right, act->next, root->right));
      } else {
        return(auxSubCamino(head, root->left, act->next, back) || auxSubCamino(head, root->right, act->next, back));
      }
    } else {
      if(act != head) return(auxSubCamino(head, back, head, back));
      if(back == nullptr) return false;
      return(auxSubCamino(head, back->left, head, back->left) || auxSubCamino(head, back->right, head, back->right));
    }
  }

  bool isSubPath(ListNode* head, TreeNode* root) {
    if (head == nullptr) return true;
    if (root == nullptr) return false;

    return auxSubCamino(head, root, head, root);
  }
};

/*
// Optimo
class Solution {
public:
  bool isSubPath(ListNode* head, TreeNode* root) {
    if (!head) {
      return true;
    }
    if (!root) {
      return false;
    }
    if (head->val == root->val && (checkSubPath(head->next, root->left) || checkSubPath(head->next, root->right))) {
      return true;
    }
    return isSubPath(head, root->left) || isSubPath(head, root->right);
  }

  bool checkSubPath(ListNode* head, TreeNode* root) {
    if (!head) {
      return true;
    }
    if (!root) {
      return false;
    }
    if (head->val == root->val) {
      return checkSubPath(head->next, root->left) || checkSubPath(head->next, root->right);
    }
    return false;
}
};
*/