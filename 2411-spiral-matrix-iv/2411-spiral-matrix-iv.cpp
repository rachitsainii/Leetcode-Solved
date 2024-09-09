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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        ListNode *temp = head;
        if(head == NULL){
            return ans;
        }

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while(top <= bottom && left <= right){
            // Move right across top row
            for(int j = left; j <= right && temp != NULL; j++){
                ans[top][j] = temp->val;
                temp = temp->next;
            }

            top++; // Move the boundary down

            // Move down the right column
            for(int i = top; i <= bottom && temp != NULL; i++){
                ans[i][right] = temp->val;
                temp = temp->next;
            }

            // Move the right boundary
            right--;

            // Move left across bottom row
            for(int j = right; j >= left && temp != NULL; j--){
                ans[bottom][j] = temp->val;
                temp = temp->next;
            }

            // Bring the bottom up
            bottom--;

            // Move up towards the top
            for(int i = bottom; i >= top && temp != NULL; i--){
                ans[i][left] = temp->val;
                temp = temp->next;
            }

            // Move left boundary right
            left++;
        }

        return ans;
    }
};