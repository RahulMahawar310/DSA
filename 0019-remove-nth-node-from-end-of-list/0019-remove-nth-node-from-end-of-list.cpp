class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast=dummy;
        ListNode* slow=dummy;

        for(int i=0; i<n; i++){
            fast=fast->next;
        }

        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }

        ListNode* del = slow->next;
        slow->next=slow->next->next;
        delete del;

        ListNode* ans= dummy->next;
        delete dummy;
        return ans;
    }
};