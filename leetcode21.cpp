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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // ListNode *temp = list1;
        ListNode *t1 = list1;
        // ListNode *temp2 = list2;
        ListNode *t2 = list2;
        // if(list1 == NULL|| list2 == NULL){
        //     return list1==NULL?list2:list1;
        // }
       
        // if(temp->val <=temp2->val){
        //     temp->next = mergeTwoLists(temp->next,list2);
        //     return list1;
        // }
        // else{
        //    temp2->next = mergeTwoLists(list1,temp2->next);
        //    return list2;
        // }
        ListNode *dummy = new ListNode(0);

        ListNode*temp = dummy;

        while(t1!=NULL && t2!=NULL){
            if(t1->val<t2->val){
                temp->next = t1;
                temp = t1;
                t1 = temp->next;
            }
            else{
                temp->next = t2;
                temp = t2;
                t2 = temp->next;
            }
        }
        if(t1){
            temp->next=t1;
        }else{
            temp->next=t2;
        }
        return dummy->next;
        
    }
};