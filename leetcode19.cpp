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
        ListNode *dummy = new ListNode(0);
        dummy->next =head;

        ListNode* temp = dummy;
        ListNode* prev = dummy;

        while(n--){
            temp = temp->next;
        }
        while(temp->next!=NULL){
            temp = temp->next;
            prev = prev->next;
        }

        prev->next = prev->next->next;

        return dummy->next;


    }
};