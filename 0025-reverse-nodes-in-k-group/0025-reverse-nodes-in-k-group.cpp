class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL ) return NULL;

        ListNode* temp = head;
        int cnt = 0;

        while(cnt < k){
            if(temp==NULL){
                return head;
            }
            temp=temp->next;
            cnt++;
        }

        ListNode* newHead = reverseKGroup(temp, k);

        temp=head;
        cnt=0;
        while(cnt<k){
            ListNode* next = temp->next;
            temp->next = newHead;
            newHead = temp;
            temp = next;

            cnt++;
        }
        return newHead;
    }
};