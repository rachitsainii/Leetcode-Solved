class Solution {
public:

    vector<int> memo;
    vector<int> cost;

    int dp(int i){
        if (i <= 1){
            return 0;
        }

        if(memo[i] != -1){
            return memo[i];
        }

        memo[i] = min(dp(i-1) + cost[i-1], dp(i-2) + cost[i-2]);

        return memo[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        this->cost = cost;
        memo = vector(cost.size()+1, -1);
        return dp(cost.size());
    }
};