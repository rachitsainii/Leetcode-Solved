class Solution {
public:

    long long dp[100000];

    long long solve(vector<vector<int>>& questions, int index){
        if(index >= questions.size()){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        long long pt = questions[index][0];
        int skip = questions[index][1];

        dp[index] = max(pt + solve(questions, index + skip+1), solve(questions, index+1));

        return dp[index];

    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        memset(dp, -1, n * sizeof(long long));

        return solve(questions, 0);

        
    }
};