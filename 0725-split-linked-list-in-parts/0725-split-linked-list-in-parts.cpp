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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        if(head == NULL && k > 0){
            while(k != 0){
                ans.push_back(NULL);
                k--;
            }

            return ans;
        }
        ListNode *temp = head;
        int n = 0;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        
        int baseSize = n / k;
        int extraNodes = n % k;
        
        temp = head;
        for(int i = 0; i < k; i++){
            ans.push_back(temp);
            int partSize = baseSize + (extraNodes > 0 ? 1 : 0);
            if(extraNodes > 0) {
                extraNodes--;
            }
            ListNode *prev = NULL;
            for(int j = 0; j < partSize; j++){
                prev = temp;
                temp = temp->next;
            }

            if(prev != NULL){
                prev->next = NULL;
            }

        }

        if(ans.size() < k){
            ans.push_back(NULL);
        }

        return ans;
    }
};