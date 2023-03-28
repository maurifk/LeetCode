// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode* l = head;
    ListNode* r = head;

    if (r == nullptr || r->next == nullptr) return false;
    
    while (r != nullptr && r->next != nullptr){
      l = l->next;
      r = r->next->next;
      if (r == l) break;
    }

    return (r == l);
  }
};