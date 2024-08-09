class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int output = 0;
        vector<int> ans = {nums[0]};
        for (int i = 1; i < nums.size(); i++){
            ans.push_back(ans.back() + nums[i]);
        }

        sort(ans.begin(), ans.end());

        if(ans[0] < 0) {
            output = abs(ans[0]) + 1;
        } else {
            output = 1;
        }

        return output;
    }
};