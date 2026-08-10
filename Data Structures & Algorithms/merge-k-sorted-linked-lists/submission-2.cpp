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
    struct comp{
        bool operator()(const ListNode* l1,const ListNode* l2){
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp>pq;
        for(auto & head : lists){
            if(head){
                pq.push(head);
            }
        }
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        while(!pq.empty()){
            ListNode* val = pq.top();
            pq.pop();
            temp->next =val;
            temp = temp->next;
            if(val->next){
                pq.push(val->next);
            }
        }
        return ans->next;
    }
};
