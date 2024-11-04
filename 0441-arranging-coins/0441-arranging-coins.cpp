class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0;
        long long sum = 0;
        for(int i = 1; i <= n; i++){
            sum += i;
            if(sum <= n){
                ans++;
            } else {
                break;
            }
        }

        return ans;
    }
};