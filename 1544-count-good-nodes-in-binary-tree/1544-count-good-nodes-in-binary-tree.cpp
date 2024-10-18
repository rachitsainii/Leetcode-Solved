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

    int dfs(TreeNode *node, int maxSoFar){

        if(node == NULL){
            return 0;
        }

        int left = dfs(node->left, max(maxSoFar, node->val));
        int right = dfs(node->right, max(maxSoFar, node->val));
        int ans = left + right;
        if(node->val >= maxSoFar){
            ans++;
        }

        return ans;
    }    

    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};