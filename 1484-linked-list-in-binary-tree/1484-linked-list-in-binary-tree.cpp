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

    bool match(ListNode *head, TreeNode *root){
        if(head == NULL){
            return true;
        }
        else if(root == NULL){
            return false;
        }
        else if(root->val != head->val){
            return false;
        }

        return match(head->next, root->left) || match(head->next, root->right);
    }

    bool dfs(ListNode *head, TreeNode *root){
        if(root == NULL){
            return false;
        }
        if(match(head, root)) {
            return true;
        }

        return dfs(head, root->left) || dfs(head, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, root);
    }
};