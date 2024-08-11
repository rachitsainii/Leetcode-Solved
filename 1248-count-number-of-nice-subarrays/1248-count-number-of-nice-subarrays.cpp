class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        counts[0] = 1;
        int ans = 0;
        int curr = 0;
        for(int i = 0; i < nums.size(); i++){
            curr += nums[i] % 2;
            ans += counts[curr - k];
            counts[curr]++;
        }

        return ans;
    }
};