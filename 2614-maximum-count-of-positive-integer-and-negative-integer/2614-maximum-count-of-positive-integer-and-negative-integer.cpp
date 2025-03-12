class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int countNeg = 0;
        int countPos = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                countNeg++;
            } else if(nums[i] > 0){
                countPos++;
            }
        }

        return max(countNeg, countPos);
    }
};