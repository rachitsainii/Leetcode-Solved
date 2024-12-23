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

    int minOps(vector<int> &v){
        int swaps = 0;
        vector<int> sortedV(v.begin(), v.end());
        sort(sortedV.begin(), sortedV.end());

        unordered_map<int, int> mp;
        for(int i = 0 ; i < v.size(); i++){
            mp[v[i]] = i;
        }

        for(int i = 0; i < v.size(); i++){
            if(v[i] == sortedV[i]){
                // No Swap required
                continue;
            }

            int currIndex = mp[sortedV[i]];
            mp[v[i]] = currIndex;
            swap(v[currIndex], v[i]);
            swaps++;
        }
        
        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        // BFS lagega isme - Level Order traversal
        // kaunsa BFS?
        // current level ke saare nodes ko process karne waala BFS.
        if(root == NULL){
            return 0;
        }
        int result = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> v;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }

            result += minOps(v);
        }

        return result;

    }
};