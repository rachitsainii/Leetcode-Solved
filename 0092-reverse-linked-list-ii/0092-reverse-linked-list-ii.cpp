/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode *rightP = head;
        while(right-1 > 0) {
            rightP = rightP->next;
            right--;
        }

        ListNode *leftP = head;
        while(left - 1 > 0) {
            leftP = leftP->next;
            left--;
        }

        cout << leftP->val << " " << rightP->val << endl;

        ListNode *curr = leftP->next;
        ListNode *prev = leftP;
        ListNode *nextNode = NULL;
        while(prev != rightP){
            if(curr->next != NULL){
                nextNode = curr->next;
            } else {
                nextNode = NULL;
            }
            curr->next = prev;
            if(prev == leftP){
                prev->next = NULL;
            }
            prev = curr;
            curr = nextNode;
        }

        if(curr == NULL){
            head = rightP;
        } else {
             head->next = rightP;
            leftP->next = curr;
        }

       

        return head;
    }
};

*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL) {
            return head; // No need to reverse if list is empty or has one node
        }

        // Move `rightP` to the correct position
        ListNode *rightP = head;
        for(int i = 1; i < right; i++) {
            rightP = rightP->next;
        }

        // Move `leftP` to the correct position
        ListNode *leftP = head;
        ListNode *prevLeftP = nullptr;  // To keep track of the node before `leftP`
        for(int i = 1; i < left; i++) {
            prevLeftP = leftP;
            leftP = leftP->next;
        }

        // Reverse the segment between `leftP` and `rightP`
        ListNode *curr = leftP->next;
        ListNode *prev = leftP;
        ListNode *nextNode = nullptr;
        while(prev != rightP) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Reconnect the reversed sublist to the rest of the list
        if(prevLeftP != nullptr) {
            prevLeftP->next = rightP;  // Connect the node before `leftP` to `rightP`
        } else {
            head = rightP;  // If `leftP` was the head, update the head to `rightP`
        }
        leftP->next = curr;  // Connect `leftP` to the node after `rightP`

        return head;
    }
};
