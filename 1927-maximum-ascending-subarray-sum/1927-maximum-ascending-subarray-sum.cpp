class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = nums[0];
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            if(nums[i] < nums[i+1]){
                currSum += nums[i+1];
                maxSum = max(maxSum, currSum);
            } else {
                currSum = nums[i+1];
                //maxSum = max(maxSum, currSum);
            }
        }

        maxSum = max(maxSum, currSum);

        return maxSum;
    }
};