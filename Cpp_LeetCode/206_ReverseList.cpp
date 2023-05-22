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
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode* it=head,* itpre=nullptr;
    

    while(it->next != nullptr){
      itpre = it;
      it = it->next;
    }

    if(itpre == nullptr) return it;

    itpre->next = nullptr;
    return new ListNode(it->val,reverseList(head));
  }
};