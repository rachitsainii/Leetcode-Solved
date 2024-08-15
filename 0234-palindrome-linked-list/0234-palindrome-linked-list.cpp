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
    bool isPalindrome(ListNode* head) {
        ListNode *head1 = head;
        if(head == NULL || head->next == NULL){
            return true;
        } 
        ListNode *curr = head;
        ListNode *prev = NULL;
        while(curr != NULL) {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        ListNode *head2 = prev;
        while(head1 != NULL && head2 != NULL){
            if(head1->val != head2->val){
                return false;
            } 
            head1 = head1->next;
            head2 = head2->next;
        }

        return true;
     }
};