class Solution {
public:
    int minimumOperations(vector<int>& nums) {      
        int n = nums.size();
        int ans = INT_MAX;

        // Case when array is small
        if (n <= 3) {
            unordered_set<int> s1;
            for (int i = 0; i < n; i++) {
                s1.insert(nums[i]);
            }

            return (s1.size() == n) ? 0 : 1;
        }

        // For larger arrays
        int p = 0;
        int count = 0;

        while (p < n) {
            unordered_set<int> s2;

            for (int i = p; i < n; i++) {
                s2.insert(nums[i]);
            }

            if (s2.size() == n - p) {
                ans = min(count, ans);
                break;
            }

            p += 3;
            count++;
        }

        return (ans == INT_MAX) ? count : ans;
    }
};
