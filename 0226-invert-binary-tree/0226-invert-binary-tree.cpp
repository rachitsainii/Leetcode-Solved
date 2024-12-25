class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }

        queue<TreeNode*> q;
        q.push(root);

        // while(!q.empty()){
        //     vector<int> temp;
        //     int n = q.size();
        //     while(n--){
        //         TreeNode *t = q.front();
        //         q.pop();
        //         // int val = t->val;
        //         // temp.push_back(val);

        //         if(t->left != NULL){
        //             q.push(t->left);
        //         }

        //         if(t->right != NULL){
        //             q.push(t->right);
        //         }

        //     }

        //     // int left = 0;
        //     // int right = temp.size() - 1;
        //     // while(left < right){
        //     //     swap(temp[left], temp[right]);
        //     //     left++;
        //     //     right--;
        //     // }

        // }

        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();

            TreeNode *temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;

            if(curr->left != NULL){
                q.push(curr->left);
            }

            if(curr->right != NULL){
                q.push(curr->right);
            }
            
        }

        return root;
        
    }
};