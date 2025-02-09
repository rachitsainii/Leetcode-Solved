class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        // Brute Force

        // int n = nums.size();
        // vector<int> prefixSum(n+1);
        // prefixSum[0] = 0;
        // int sum = 0;
        // for(int i = 0; i < n; i++){
        //     sum += nums[i];
        //     prefixSum[i] = sum;
        // }

        // for(auto i : prefixSum){
        //     cout << i << " ";
        // }

        // cout << endl;

        // int ans = 0;

        // for(int i = 0; i < n+1; i++){
        //     for(int j = i+1; j< n+1; j++){
        //         if((prefixSum[i] - prefixSum[j]) % k == 0){
        //             ans++;
        //         }
        //     }
        // }

        // return ans;

        unordered_map<int,int> counts;
        counts[0] = 1;

        int prefixSum = 0;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            int mod = (prefixSum % k + k) % k;

            if(counts.find(mod) != counts.end()){
                ans+= counts[mod];
            }

            counts[mod]++;

        }

        return ans;

    }
};