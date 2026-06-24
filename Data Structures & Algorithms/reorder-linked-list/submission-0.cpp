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
    void reorderList(ListNode* head) {
        // center
        ListNode *slow = head, *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        // reverse
        ListNode *prev = nullptr;
        ListNode *tmp = slow->next;
        slow->next = nullptr;
        while(tmp != nullptr){
            slow = tmp;
            tmp = tmp->next;
            slow->next = prev;
            prev = slow;
        }

        // merge
        bool odd = false;
        // new list
        ListNode *start = new ListNode(0);
        while(head != nullptr || prev != nullptr){
            if(!odd){
                start->next = head;
                head = head->next;
                odd = true;
            } else{
                start->next = prev;
                prev = prev->next;
                odd = false;
            }
            start = start->next;
        }
        // head = start->next;
    }
};
