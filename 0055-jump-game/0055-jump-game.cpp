class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            maxi = max(maxi, nums[i] + i);
            if(maxi <= i){
                return false;
            }
        }

        return true;
    }
};