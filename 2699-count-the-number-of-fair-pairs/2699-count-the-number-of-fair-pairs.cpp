class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            int left = i + 1;
            int lowBound = lower - nums[i];
            int upBound = upper - nums[i];

            
            auto low = lower_bound(nums.begin() + left, nums.end(), lowBound);
            auto high = upper_bound(nums.begin() + left, nums.end(), upBound);

            ans += high - low;
        }

        return ans;
    }
};
