class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // Solution using Prefix Sum approach

        // Step 1: Create the prefix sum array
        vector<long int> prefix_sum = {nums[0]};
        for(int i = 1; i < nums.size(); i++){
            prefix_sum.push_back(prefix_sum.back() + nums[i]);
        }

        int ans = 0;

        // Step 2: Work on the prefix sum array as per the requirement
        for (int j = 1; j < prefix_sum.size(); j++){
            long int sum_left_subArray = prefix_sum[j-1];
            long int sum_right_subArray = prefix_sum[prefix_sum.size()-1] - prefix_sum[j-1];
            if(sum_left_subArray >= sum_right_subArray) {
                ans ++;
            } else {
                continue;
            }
        }

        return ans;
        
    }
};