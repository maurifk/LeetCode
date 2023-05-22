#include <unordered_map>
using namespace std;

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
  ListNode* reverseList(ListNode* head, ListNode* sigs) {
    if (head == nullptr) return sigs;
    ListNode* it=head,* itpre=nullptr;
    

    while(it->next != nullptr){
      itpre = it;
      it = it->next;
    }

    if(itpre == nullptr) {
      it->next=sigs;
      return it;
    }

    itpre->next = nullptr;
    return new ListNode(it->val,reverseList(head, sigs));
  }

  ListNode* reverseBetween(ListNode* head, int left, int right) {
    unordered_map<int,ListNode*> mapa;
    int it = 1;
    ListNode* itP = head;

    while (itP != nullptr){
      mapa[it] = itP;
      it++;
      itP = itP->next;
    }
    mapa[0] = nullptr;
    mapa[it] = nullptr;

    mapa[right]->next = nullptr;

    if(left == 1){
      return reverseList(head, mapa[right+1]);
    } else {
      mapa[left-1]->next = reverseList(mapa[left], mapa[right+1]);
      return head;
    }
  }
};