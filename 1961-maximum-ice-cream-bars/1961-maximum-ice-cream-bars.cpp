class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        sort(costs.begin(), costs.end());

        if(costs[0] > coins){
            return 0;
        }

        int ans = 0;
        int it = 0;
        while(coins > 0 && it < costs.size()){
            if(coins - costs[it] >= 0){
                coins -= costs[it];
            } else {
                return ans;
            }
            ans++;
            it++;
        }

        return ans;
    }
};