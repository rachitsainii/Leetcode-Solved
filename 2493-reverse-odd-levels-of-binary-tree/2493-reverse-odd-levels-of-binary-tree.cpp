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
    TreeNode* reverseOddLevels(TreeNode* root) {
        // Ek baar mei pooora level process karne waala BFS apply hoga.
        // TC - O(n)
        // SC = O(n)
        if(root == NULL){
            return root;
        }

        queue<TreeNode*> q;
        q.push(root);

        int lvl = 0;

        while(!q.empty()){
            int n = q.size();
            vector<TreeNode*> lvlNodes;
            while(n--){
                TreeNode *temp = q.front();
                q.pop();
                lvlNodes.push_back(temp);

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }
            }

            if(lvl % 2 == 1){
                int i = 0;
                int j = lvlNodes.size() - 1;

                while(i < j){
                    int tempVal = lvlNodes[i]->val;
                    lvlNodes[i]->val = lvlNodes[j]->val;
                    lvlNodes[j]->val = tempVal;
                    i++;
                    j--;
                }
            }

            lvl++;
        }
        
        return root;
        
    }
};