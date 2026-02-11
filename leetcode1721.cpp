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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int n = k;
        ListNode *temp = dummy;
        while(n--){
            temp=temp->next;
        }
        ListNode *first = temp;
        ListNode *temp2 = dummy;
        while(temp!=NULL){
            temp = temp->next;
            temp2= temp2->next;
        }
        // for(int i = 0;i<k;i++){
        //     first = first->next;
        // }
        
        swap(temp2->val,first->val);
        return head;
    }
};