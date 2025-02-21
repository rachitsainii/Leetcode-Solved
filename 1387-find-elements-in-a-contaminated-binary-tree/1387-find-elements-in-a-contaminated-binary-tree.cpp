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
class FindElements {
public:

    unordered_set<int> values;

    void bfs(TreeNode *root, int x){
        queue<TreeNode* > q;
        root->val = x;
        q.push(root);

        while(!q.empty()){
            TreeNode *n = q.front();
            q.pop();

            values.insert(n->val);

            if(n->left != NULL){
                n->left->val = 2 * (n->val) + 1;
                //values.insert(n->left->val);
                q.push(n->left);
            }

            if(n->right != NULL){
                n->right->val = 2 * (n->val) + 2;
                //values.insert(n->right->val);
                q.push(n->right);
            }
        }
    }

    FindElements(TreeNode* root) {
       values.clear();
       bfs(root, 0);
    }
    
    bool find(int target) {
        return values.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */