#include <set>
#include <unordered_map>
using namespace std;

 // Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

/*
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    set<ListNode*> setv;
    ListNode* p = head;

    while (p != nullptr){
      if(setv.count(p)){
        break;
      } else {
        setv.insert(p);
        p = p->next;
      }
    }

    return p;
  }
};
*/
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    unordered_map<ListNode*, int> map;
    ListNode* p = head;

    while (p != nullptr){
      if(map.count(p)){
        break;
      } else {
        map[p] = p->val;
        p = p->next;
      }
    }

    return p;
  }
};