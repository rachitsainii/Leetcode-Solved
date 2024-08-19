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

    pair<bool, int> fastBalanced(TreeNode *root){
        if(root == NULL){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        pair<bool, int> left = fastBalanced(root->left);
        pair<bool, int> right = fastBalanced(root->right);
        bool val1 = left.first;
        bool val2 = right.first;
        bool val3 = abs(left.second - right.second) <= 1;
        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;
        if(val1 && val2 && val3){
            ans.first = true;
        } else {
            ans.first = false;
        }

        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return fastBalanced(root).first;
    }
};