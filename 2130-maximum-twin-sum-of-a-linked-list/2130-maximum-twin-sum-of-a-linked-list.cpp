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
    int pairSum(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *curr = slow->next;
        ListNode *prev = NULL;
        while(curr != NULL) {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        slow->next = prev;


        ListNode *s = head;
        ListNode *f = prev;
        
        int ans = 0;
        while(f!= NULL){
            ans = max(ans, (f->val + s->val));
            f = f->next;
            s = s->next;
        }

        return ans;
    }

};