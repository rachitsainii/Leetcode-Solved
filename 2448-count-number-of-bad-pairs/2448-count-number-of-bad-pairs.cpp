class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long total_pairs = (1LL* n * (n-1)) / 2;
        long long good_pairs = 0;
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++){
            int key = nums[i] - i;
            good_pairs += freq[key];
            freq[key]++;
        }

        return total_pairs - good_pairs;
    }
};