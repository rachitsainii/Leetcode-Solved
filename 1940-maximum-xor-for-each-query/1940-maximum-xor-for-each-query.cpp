class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int n = nums.size();
        int x = 0; 


        for (int i = 0; i < n; i++) {
            x ^= nums[i];
        }

        int max_val = (1 << maximumBit) - 1;
                
        for (int i = n - 1; i >= 0; i--) {
            ans.push_back(x ^ max_val);  
            x ^= nums[i];
        }

        return ans;
    }
};
