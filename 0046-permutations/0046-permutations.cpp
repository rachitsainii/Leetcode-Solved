class Solution {
public:

    vector<vector<int>> result;
    unordered_set<int> st;

    void backtrack(vector<int> &temp, vector<int> &nums){
        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(st.find(nums[i]) == st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);

                backtrack(temp, nums);

                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        backtrack(temp, nums);

        return result;
    }
};