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
    void merge(ListNode* l1, ListNode*l2){
        ListNode *dummy = new ListNode(0);
        ListNode * temp = dummy;
        while (l1 && l2) {
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }
        if(l1){
            temp->next = l1;
        }
        else{
            temp->next = l2;
        }
    }
    ListNode * ReverseList(ListNode* l1){
        ListNode *curr = l1;
        ListNode *prev = NULL;
        while(curr!=NULL){
            ListNode *forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
    if (head==NULL || head->next==NULL) return;
       ListNode* fast = head;
       ListNode* slow = head;
       ListNode* prev = NULL;


       while(fast && fast->next){
        prev = slow;
        slow= slow->next;
        fast= fast->next->next;
       }
       prev->next = NULL;

       ListNode *l1 = head;
       ListNode *l2 = ReverseList(slow);
        merge(l1,l2);
       
    }
};