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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode *dummy = head->next;
        ListNode *prev = NULL;

        while(head != NULL && head->next != NULL) {
            if(prev != NULL){
                prev->next = head->next;
            }
            prev = head;
            ListNode *nextNode = head->next->next;
            head->next->next = head;
           
            head->next = nextNode;
            head = nextNode;
            }            
        return dummy;
    }
};