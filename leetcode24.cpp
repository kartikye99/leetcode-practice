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
    ListNode* swapPairs(ListNode* head) {
        ListNode * dummy = new ListNode(0);

        dummy->next = head;
        ListNode* curr = dummy;

        while(curr->next && curr->next->next){
            ListNode *temp = curr->next->next;

            curr ->next->next =  temp->next;
            temp->next = curr->next;
            curr->next = temp;

            curr = curr->next->next;
        }
        return dummy->next;
    }
};