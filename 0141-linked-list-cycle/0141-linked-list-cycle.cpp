/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        // Approach 1 : Using Slow and Fast Pointers. (Time O(n) , Space O(1))
        ListNode *slow = head;
        ListNode *fast = head;
        if(head == NULL || head->next == NULL){
            return false;
        }
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false; 

        // Approach 2 : Using a Hashset (Time and Space : O(n))
        /* unordered_set<int> check;
        ListNode *temp = head;
        while(temp != NULL){
            if(check.find(temp->val) != check.end()){
                return true;
            } else {
                check.insert(temp->val);
                temp = temp->next;
            }
            
        }

        return false; */
    }
};