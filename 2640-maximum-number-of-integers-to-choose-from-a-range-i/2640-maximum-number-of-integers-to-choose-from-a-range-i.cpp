class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> b(banned.begin(), banned.end());
        long sum = 0;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(b.find(i) != b.end()){
                continue;
            } else{
                if(maxSum - i  >= 0){
                    maxSum -= i;
                    ans++;
                } else  {
                    return ans;
                }
            }
        }

        return ans;
    }
};