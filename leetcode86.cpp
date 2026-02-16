class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);
        ListNode* dummy2 = new ListNode(0);

        ListNode* d = dummy;
        ListNode* d2 = dummy2;
        ListNode* temp = head;

        while (temp != nullptr) {
            if (temp->val < x) {
                d->next = temp;
                d = d->next;
            } else {
                d2->next = temp;
                d2 = d2->next;
            }
            temp = temp->next;
        }


        d2->next = nullptr;

        d->next = dummy2->next;

        return dummy->next;
    }
};
