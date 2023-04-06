#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> s;
    ListNode* p = head;

    while (p != nullptr){
      if(s.count(p)){
        break;
      } else {
        s.insert(p);
        p = p->next;
      }
    }

    return !(p == nullptr);
  }
};