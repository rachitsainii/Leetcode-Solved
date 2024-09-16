class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<int> leftSum(nums.size());
        vector<int> rightSum(nums.size());
        vector<int> prefix_sum;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            prefix_sum.push_back(sum);
        }

        for(int i = 0; i < nums.size(); i++){
            leftSum[i] = prefix_sum[i] - nums[i];
        }

        for(int i = 0; i < nums.size(); i++){
           rightSum[i] = prefix_sum[nums.size()-1] - prefix_sum[i];
        }

        for(int i = 0; i < nums.size(); i++){
            ans[i] = abs(leftSum[i] - rightSum[i]);
        }

        return ans;
    }
};