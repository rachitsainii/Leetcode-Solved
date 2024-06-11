class Solution {
public:
    // Normal Recursion
    int solveUsingRecursion(int n){
        // Base Case (Mandatory)
        if(n == 0 || n == 1){
            return n;
        }

        // Processing (Optional)

        // Recursive Relation (Mandatory)
        int ans = solveUsingRecursion(n-1) + solveUsingRecursion(n-2);

        return ans;
    }

    // Top-down approach
    // Recommended approach
    int solveUsingMemoization(int n, vector<int> &dp){
        // Base Case (Mandatory)
        if(n == 0 || n == 1){
            return n;
        }

        // step 3: If answer already exists then return ans
        if(dp[n] != -1){
            return dp[n];
        }

        // Step 2: Store and return using dp array
        dp[n] = solveUsingMemoization(n-1, dp) + solveUsingMemoization(n-2, dp);

        return dp[n];

    }

    int solveUsingTabulation(int n){
        // Step I: Create a DP array.
        vector<int> dp(n+1, -1);
        // Step II: Analyze base case and fill dp array
        dp[0] = 0;
        if(n==0){
            return dp[0];
        }
        dp[1] = 1;
        // Step III: Fill the remaining dp array
        //size = n + 1;
        // index -> 0 - n
        // Kaunse fill ho chuke hai 0 aur 1
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        // Answer return;
        return dp[n];

    }

    int fib(int n) {

        // int ans = solveUsingRecursion(n);
        // return ans;
        // Step 1: Create a DP array
        // vector<int> dp(n+1, -1);
        // int ans = solveUsingMemoization(n, dp);
        // return ans;
        int ans = solveUsingTabulation(n);
        return ans;
        
    }
};