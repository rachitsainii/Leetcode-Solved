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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        stack<pair<TreeNode*, int >> stack;
        stack.push(make_pair(root, 1));
        int ans = 0;

        while(!stack.empty()){
            auto [node, depth] = stack.top();
            stack.pop();
            ans = max(ans, depth);

            if(node->left != NULL){
                stack.push(make_pair(node->left, depth+1));
            }

            if(node->right != NULL){
                stack.push(make_pair(node->right, depth+1));
            }
        }

        return ans;
    }
};