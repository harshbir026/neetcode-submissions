class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        
        if (fast == nullptr) {
            ListNode* newHead = head->next;
            
            return newHead;
        }

       
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        
        
        return head;
    }
};