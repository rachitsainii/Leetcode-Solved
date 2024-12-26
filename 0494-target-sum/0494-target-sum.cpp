class Solution {
public:

    int solve(vector<int> &nums, int target, int i, int currSum){
        if(i == nums.size()){
            if(currSum == target){
                return 1; // We found 1 way to reach target;
            } else {
                return 0;
            }
        }

        int plus = solve(nums, target, i+1, currSum + nums[i]);
        int minus = solve(nums, target, i+1, currSum - nums[i]);

        return plus + minus; // Total ways.
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, 0);
    }
};