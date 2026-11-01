class Solution {
public:
    void reorderList(ListNode* head) {
       
        if (head == NULL || head->next == NULL) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;   
        slow->next = NULL;               

        ListNode* prev = NULL;
        ListNode* curr = second;
        while (curr != NULL) {
            ListNode* nextNode = curr->next; 
            curr->next = prev;                
            prev = curr;
            curr = nextNode;
        }

        ListNode* first = head;
        second = prev;                        
        while (second != NULL) {
            ListNode* t1 = first->next;       
            ListNode* t2 = second->next;      

            first->next = second;             
            second->next = t1;                

            first = t1;                       
            second = t2;
        }
    }
};