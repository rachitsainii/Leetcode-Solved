class Solution {
public:

    int solveUsingRecursion(vector<int> &coins, int amount){
        // Base Case
        if(amount == 0){
            return 0;
        }

        // Recursive Relation
        int mini = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            // find ans using ith coin
            if(amount - coins[i] >= 0){
                int recursionAns = solveUsingRecursion(coins, amount - coins[i]);
                if(recursionAns != INT_MAX){
                    int ans = 1 + recursionAns;
                    mini = min(mini, ans);
                }
                
            }
            
        }

        return mini;

    }

    // Using Memoization

    int solveUsingMem(vector<int> &coins, int amount, vector<int> &dp){
        // Base Case
        if(amount == 0){
            return 0;
        }

        // If ans exists
        if(dp[amount] != -1){
            return dp[amount];
        }

        // Recursive Relation
        int mini = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            // find ans using ith coin
            if(amount - coins[i] >= 0){
                int recursionAns = solveUsingMem(coins, amount - coins[i], dp);
                if(recursionAns != INT_MAX){
                    int ans = 1 + recursionAns;
                    mini = min(mini, ans);
                }
                
            }
            
        }
        dp[amount] = mini;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = amount;
        vector<int> dp(n+1, -1);
        int ans = solveUsingMem(coins, amount, dp);
        // int ans =  solveUsingRecursion(coins, amount);
        if(ans == INT_MAX){
            return -1;
        } else {
            return ans;
        }
        
    }
};