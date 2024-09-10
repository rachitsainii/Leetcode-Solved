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

    int gcd(int x, int y){
        if(x == 0){
            return y;
        }
        if(y == 0){
            return x;
        }

        if(x == y){
            return x;
        }
        if(x > y){
            return gcd((x-y), y);
        }

        return gcd(x, (y-x));
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL){
            return head;
        }
        ListNode *temp = head->next;
        ListNode *prev = head;
        while(temp != NULL){
            int value = gcd(prev->val, temp->val);
            ListNode * node = new ListNode(value);
            node->next = temp;
            prev->next = node;
            prev = temp;
            temp = temp->next;

        }

        return head;
    }
};