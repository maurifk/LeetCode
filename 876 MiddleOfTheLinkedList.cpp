
 // Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

  
class Solution {
public:
  ListNode* middleNode(ListNode* head) {
    if (head->next == nullptr) return head;
    ListNode* lento = head;
    ListNode* rapido = head;
    while(rapido != nullptr && rapido->next != nullptr){
      rapido = rapido->next->next;
      lento = lento->next;
    }
    
    return lento;
  }
};