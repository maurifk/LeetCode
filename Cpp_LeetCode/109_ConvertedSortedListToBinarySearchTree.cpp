struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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
  TreeNode* sortedListToBST(ListNode* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return &TreeNode(head->val);

    ListNode* lento = head;
    ListNode* rapido = head; 
    ListNode* anterior = head;

    while ((rapido != nullptr) && (rapido->next != nullptr)){
      rapido = rapido->next->next;
      anterior = lento;
      lento = lento->next;
    }

    anterior->next = nullptr;
    return &TreeNode(lento->val, sortedListToBST(head), sortedListToBST(lento->next));
  }
};