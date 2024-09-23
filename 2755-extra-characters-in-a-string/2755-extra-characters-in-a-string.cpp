class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> wordSet(dictionary.begin(), dictionary.end());
        int n = s.length();

        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0; // No extra characters for an empty string

        for(int i = 1; i <=n; i++){
            dp[i] = dp[i-1] + 1;

            for(int j = 0; j < i; j++){
                if(wordSet.count(s.substr(j, i-j))){
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }

        return dp[n];
    }
};