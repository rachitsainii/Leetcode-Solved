class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 3){
            return 0;
        }

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int option1 = nums[n-1] - nums[3]; // Remove 3 smallest elements;
        int option2 = nums[n-2] - nums[2]; // Remove 2 smallest, 1 largest;
        int option3 = nums[n-3] - nums[1]; // Remove 1 smallest, 2 largest;
        int option4 = nums[n-4] - nums[0]; // Remove 3 largest;

        return min({option1,option2,option3,option4});
    }
};