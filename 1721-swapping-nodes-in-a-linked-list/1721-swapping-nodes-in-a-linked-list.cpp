class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first=head;

        for(int i=1; i<k; i++){
            first=first->next;
        }
        ListNode* a=first;

        ListNode* second = head;
        while(first->next!=NULL){
            first=first->next;
            second=second->next;
        }

        int temp=a->val;
        a->val=second->val;
        second->val=temp;

        return head;
    }
};