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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }

        if (head->next == NULL && n != 0){
            delete(head);
            return NULL;

        }

        ListNode *slow = head;
        ListNode *curr = head->next;
        ListNode *fast = head;
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }

        if(fast == NULL){
            ListNode *temp = head;
            head = head->next;
            delete(temp);
            return head;

        }

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            curr = curr->next;
            fast = fast->next;

        }

        if(curr == fast) {
            slow->next = NULL;
        } else {
            slow->next = curr->next;
            curr->next = NULL;
        }

       

        return head;
        
    }
};