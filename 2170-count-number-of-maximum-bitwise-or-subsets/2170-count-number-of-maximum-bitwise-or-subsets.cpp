class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int ans = 0;
        int max_or = 0;
        for(int i = 0; i < nums.size(); i++){
            max_or = max_or | nums[i];
        }

        int n = nums.size();
        int total_subsets = 1 << n;

        for(int subset_mask = 1; subset_mask < total_subsets; subset_mask++){
            int subset_or = 0;

            for(int i = 0; i < n; i++){
                if(subset_mask & (1 << i)){
                    subset_or |= nums[i];
                }
            }

            if(subset_or == max_or){
                ans++;
            }

        }
        

        return ans;
    }
};