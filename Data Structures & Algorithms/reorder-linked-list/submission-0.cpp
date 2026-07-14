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

    ListNode* reversee(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            ListNode* nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        return prev;

    }
    void reorderList(ListNode* head) {
     //   ListNode* temp = head;
     if (!head || !head->next || !head->next->next) return;
        ListNode* slow = head;
        ListNode* fast = head->next ;

        while(fast != nullptr && fast->next!= nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second_half_rev= reversee(slow->next);
        //reversee(mid);
        slow->next = nullptr;

        ListNode* first_half = head;

        while(second_half_rev){
            ListNode* temp1 = first_half->next;
            ListNode* temp2 = second_half_rev->next;

            first_half->next = second_half_rev;
            second_half_rev->next = temp1;

            first_half = temp1;
            second_half_rev = temp2;
        }

        //head = first_half;

    }
};
