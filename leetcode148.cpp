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
    ListNode *Mergelist(ListNode* l1, ListNode*l2){
        ListNode dummy(0);
        ListNode* temp = &dummy;
        while(l1&&l2){
            if(l1->val<l2->val){
                temp->next = l1;
                l1=l1->next;
            }
            else{
                temp->next = l2;
                l2= l2->next;
            }
            temp = temp->next;
        }
        if(l1){
            temp->next=l1;
        }
        else{
            temp->next=l2;
        }
        return dummy.next;

    }



    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode * fast = head;
        ListNode * slow = head;
        ListNode * prev = NULL;

        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow=slow->next;
            fast = fast->next->next;
        }

        prev->next=NULL;

        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);

        return Mergelist(l1,l2);
    }
};