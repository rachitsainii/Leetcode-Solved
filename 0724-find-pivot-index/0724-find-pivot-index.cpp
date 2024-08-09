class Solution {
public:
    int pivotIndex(vector<int>& nums) {
            int ans = -1;
            // Calculate the prefix sum
            vector<int> prefix_sum = {0, nums[0]};
            for (int i = 1; i < nums.size(); i++){
                prefix_sum.push_back(prefix_sum.back() + nums[i]);
            }

            for(int j = 0; j < nums.size(); j++){
                int leftSum = prefix_sum[j];
                int rightSum = prefix_sum[prefix_sum.size()-1] - prefix_sum[j+1];
                if (leftSum == rightSum) {
                    ans = j;
                    break;
                }
            }

            return ans;
    }
};