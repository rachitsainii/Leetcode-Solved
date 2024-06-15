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
    int solveUsingTabulation(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n-1] = nums[n-1];
        for(int index = n-2; index >= 0; index--){
            int tempAns = 0;
            if(index+2 < n){
                tempAns = dp[index+2];
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + dp[index+1];
            dp[index] = max(include, exclude);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
        int index = 0;
        //int ans = solveUsingRecursion(nums, index);
        //return ans;
        int n = nums.size();
        // vector<int> dp(n, -1);
        // int ans = solveUsingMem(nums, dp, index);
        // return ans;
        int ans = solveUsingTabulation(nums);
        return ans;
    }
};