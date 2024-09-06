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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(head == NULL){
            return head;
        }

        if(nums.size() == 0){
            return head;
        }

        unordered_set<int> numbers;
        for(auto i : nums){
            numbers.insert(i);
        }
        
        
        ListNode *temp = head;
        ListNode *prev = NULL;
        while(temp != NULL){
            if((numbers.find(temp->val) != numbers.end()) && temp == head){
                ListNode *n = temp->next;
                temp->next = NULL;
                ListNode * del = temp;
                temp = n;
                head = temp;
                delete(del);
            } else if((numbers.find(temp->val) != numbers.end()) && temp != head){
                ListNode *n = temp->next;
                prev->next = temp->next;
                temp->next = NULL;
                ListNode * del = temp;
                temp = n;
                delete(del);
            } else if ((numbers.find(temp->val) != numbers.end()) && temp->next == NULL){
                prev->next = NULL;
                delete(temp);
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        
        return head;
    }
};