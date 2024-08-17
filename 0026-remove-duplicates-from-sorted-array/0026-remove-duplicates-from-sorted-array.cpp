class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 1;
        int j = 1;
        for(left = 1; left < nums.size(); left++){
            if(nums[left] != nums[left-1]){
                nums[j] = nums[left];
                j++;
            }
        }

        return j;
    }
};