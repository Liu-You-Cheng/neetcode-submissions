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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int l1v = 0, l2v = 0;
        ListNode *ans = new ListNode(0);
        ListNode *cur = ans;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            l1v = l1 != nullptr ? l1->val : 0;
            l2v = l2 != nullptr ? l2->val : 0;
            auto sum = l1v + l2v + carry;
            if(sum >= 10){
                carry = 1;
                sum -= 10;
            }else{
                carry = 0;
            }
            ListNode *tmp = new ListNode(sum);
            cur->next = tmp;
            cur = cur->next;
            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
        }

        return ans->next;
    }
};
