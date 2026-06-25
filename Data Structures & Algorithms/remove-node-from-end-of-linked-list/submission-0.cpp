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
        ListNode *start = new ListNode(0), *fast = head;
        start->next = head;
        // fast goes first
        for(int i = 1; i <= n ; i++){
            fast = fast->next;
        }

        // trav
        ListNode *prev = start;
        while(fast != nullptr){
            prev = prev->next;
            fast = fast->next;
        }
        
        if(prev == start){
            return head->next;
        }
        ListNode *tmp = prev->next;
        prev->next = tmp->next;
        delete(tmp);
        return head;        
    }
};
