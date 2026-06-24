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
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // reverse
        ListNode* prev = nullptr;
        ListNode* tmp = slow->next;
        slow->next = nullptr;
        while (tmp != nullptr) {
            slow = tmp;
            tmp = tmp->next;
            slow->next = prev;
            prev = slow;
        }

        // merge
        bool odd = false;
        ListNode* start = new ListNode(0);
        ListNode* tail = start;

        ListNode* p1 = head;
        ListNode* p2 = prev;

        while (p1 != nullptr || p2 != nullptr) {
            if (!odd) {
                tail->next = p1;
                p1 = p1->next;
                odd = true;
            } else {
                tail->next = p2;
                p2 = p2->next;
                odd = false;
            }
            tail = tail->next;
        }

        tail->next = nullptr;

        delete start;
    }
};
