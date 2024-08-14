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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL) {
            return head;
        }

        if(head->next == NULL){
            return NULL;
        }
        int count = 0;
        ListNode *temp = head;
        while(temp != NULL){
            count++;
            temp = temp ->next;
        }

        int middleNode = count / 2;
        ListNode *prev = head;
        for(int i = 0; i < middleNode-1; i++){
            prev = prev->next;
        }

        ListNode *curr = prev->next;
        prev->next = curr->next;
        curr->next = NULL;
        delete(curr);
        

        return head;
    }
};