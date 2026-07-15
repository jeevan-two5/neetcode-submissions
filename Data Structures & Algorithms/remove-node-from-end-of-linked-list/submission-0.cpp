/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* temp  = head;
        int len =0;
        while(temp){
            len++;
            temp = temp->next;
        }

        if(len == n) return head->next;
        temp = head;
        int cnt = 0;
        
        while(cnt<len-n-1 && temp != nullptr){
            cnt++;
            temp = temp->next;
            
        }

       // ListNode* bef = temp->next->next;

      if(temp->next != nullptr)  temp->next = temp->next->next;
      return head;


    }
};
