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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode *currNode = head;
        ListNode *nextNode = head->next;
        while(nextNode != NULL){
            if(currNode->val == nextNode->val){
                // Delete the nextNode;
                currNode->next = nextNode->next;
                ListNode *temp = nextNode;
                nextNode = nextNode->next;
                delete temp;
            } else {
                currNode = currNode->next;
                nextNode = nextNode->next;
            }
        }

        return head;
    }
};