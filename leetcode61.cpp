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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL|| head->next==NULL) return head;

        int count = 1;
        ListNode* temp = head;

        while(temp->next!=NULL){
            temp = temp->next;
            count++;
        }

        k = k%count;
        if(k==0) return head;

        temp->next = head;
        
        int n = count-k-1;
        temp->next = head;

        ListNode* temp2 = head;

        for(int i = 0;i<n;i++){
            temp2=temp2->next;
        }

        head = temp2->next;
        temp2->next = NULL;
        return head;

    }
};