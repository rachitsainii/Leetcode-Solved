/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            while(n--){
                TreeNode *t = q.front();
                q.pop();
                temp.push_back(t->val);

                if(t->left != NULL){
                    q.push(t->left);
                }

                if(t->right != NULL){
                    q.push(t->right);
                }
            }

            sort(temp.begin(), temp.end());
            ans.push_back(temp[temp.size() - 1]);
        }

        return ans;
    }
};