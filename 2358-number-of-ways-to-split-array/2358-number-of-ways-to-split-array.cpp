class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long> prefix_sum(n);
        long sum = 0;
        for(int i = 0 ; i < nums.size(); i++){
            sum += nums[i];
            prefix_sum[i] = sum;
        }

        for(auto i : prefix_sum){
            cout << i << endl;
        }

        int ans = 0;

        for(int i = 0; i < prefix_sum.size()-1; i++){
            if(prefix_sum[i] >= (prefix_sum[n-1] - prefix_sum[i])){
                ans++;
            }
        }

        return ans;
    }
};