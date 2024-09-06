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


        for(auto i : nums){
            ListNode *temp = head;
            ListNode *prev = NULL;
            while(temp != NULL){
                if(temp->val == i && temp == head){
                    ListNode *n = temp->next;
                    temp->next = NULL;
                    temp = n;
                    head = temp;
                } else if(temp->val == i && temp != head){
                    ListNode *n = temp->next;
                    prev->next = temp->next;
                    temp->next = NULL;
                    // prev = temp;
                    temp = n;
                } else if (temp->val == i && temp->next == NULL){
                    ListNode *p = NULL;
                    while(p->next != temp){
                        p = p->next;
                    }
                    p->next = NULL;
                } else {
                    prev = temp;
                    temp = temp->next;
                }
            }
        }

        return head;
    }
};