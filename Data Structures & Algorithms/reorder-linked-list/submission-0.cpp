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
    ListNode* reverse(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        int k = len / 2;
        temp = head;
        for (int i = 0; i < k; i++) {
            temp = temp->next;
        }
        ListNode* front = temp->next;
        temp->next = NULL;
        temp = head;
        ListNode* rev = reverse(front);
        while (rev != nullptr && temp != nullptr) {
            ListNode* agla = temp->next;
            temp->next = rev;
            temp = agla;
            ListNode* agla2 = rev->next;
            rev->next = temp;
            rev = agla2;
        }
    }
};
