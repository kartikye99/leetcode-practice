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
    ListNode* partition(ListNode* head, int x) {

        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *l1 = new ListNode(0);
        ListNode *l2 = new ListNode(0);

        ListNode *d1 = l1;
        ListNode *d2 = l2;
        ListNode *temp = head;

        while(temp!=NULL){
            if(temp->val < x){
                d1->next = temp;
                d1 = d1->next;
            }
            else{
                d2->next = temp;
                d2 = d2->next;
            }

            temp = temp->next;
        }

        d2->next = NULL;
        d1->next = l2->next;

        return l1->next;

    }
};