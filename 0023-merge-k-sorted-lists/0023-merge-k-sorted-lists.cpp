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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        int n = lists.size() - 1;
        vector<int> values;
        for(int i = 0; i <= n; i++){
            ListNode * temp = lists[i];
            while(temp != NULL){
                values.push_back(temp->val);
                temp = temp->next;
            }
        }

        if(values.empty()){
            return NULL;
        }

        sort(values.begin(), values.end());

         for(auto i : values){
            cout << i << " ";
        }

        ListNode * temp = new ListNode();
        ListNode *head = temp;
        temp->val = values[0];
        temp->next = NULL;
        for(int i = 1 ; i < values.size(); i++){
            ListNode *node = new ListNode();
            temp->next = node;
            node->val = values[i];
            temp = node;
            node->next = NULL;
            
        }

        return head;
    }
};