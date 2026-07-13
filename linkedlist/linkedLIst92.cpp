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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || head->next==nullptr){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prevleft = dummy;
        ListNode *start = head;
        ListNode *end = head;

        for(int i = 1 ; i<left; i++){
            prevleft = start;
            start = start->next;
        }

        for(int i = 1 ; i<=right;i++){
            end = end->next;
        }

        ListNode *curr = start;
        ListNode *prev = end;

        while(curr!=end){
            ListNode *forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        prevleft->next = prev;
        return dummy->next;
    }
};