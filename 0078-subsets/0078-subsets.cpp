class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        for(int i = 0; i < nums.size(); i++){
            int n = ans.size();
            for(int j = 0; j < n; j++){
                vector<int> subset  = ans[j];
                subset.push_back(nums[i]);
                ans.push_back(subset);
            }
        }

        return ans;
    }
};