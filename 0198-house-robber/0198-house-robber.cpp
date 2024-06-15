class Solution {
public:

    int solveUsingRecursion(vector<int> &nums, int index){
        // Base Case
        if(index >= nums.size()){
            return 0;
        }

        // Recursive relation
        int include = nums[index] + solveUsingRecursion(nums, index+2);
        int exclude = 0 + solveUsingRecursion(nums, index+1);
        int ans = max(include, exclude);
        return ans;
    }

    // Top-Down (Memoization)
    int solveUsingMem(vector<int> &nums, vector<int> &dp, int index){
        // Base Case
        if(index >= nums.size()){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        // Recursive relation
        int include = nums[index] + solveUsingMem(nums, dp, index+2);
        int exclude = 0 + solveUsingMem(nums, dp, index+1);
        dp[index] = max(include, exclude);
        return dp[index];
        
    }

    // Tabulation
    // int solveUsingTabulation(vector<int> &nums){
    //     int n = nums.size();
    //     vector<int> dp(n+1, -1);
    // }

    int rob(vector<int>& nums) {
        int index = 0;
        //int ans = solveUsingRecursion(nums, index);
        //return ans;
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = solveUsingMem(nums, dp, index);
        return ans;
    }
};