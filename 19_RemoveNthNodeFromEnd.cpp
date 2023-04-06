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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* iter = head;
    unordered_map<int, ListNode*> map;
    int i = 1;

    while (iter != nullptr){
      map[i] = iter;
      i++;
      iter = iter->next;
    }

    int nodoAElim = i-n;
    if (nodoAElim == 1){
      if(i == 1){
        delete head;
        return nullptr;
      }
      ListNode* temp = head->next;
      delete head;
      return temp;
    }
    
    map[i+1] = nullptr;
    
    map[nodoAElim-1]->next = map[nodoAElim+1];
    delete map[nodoAElim];
    return head; 
  }
};