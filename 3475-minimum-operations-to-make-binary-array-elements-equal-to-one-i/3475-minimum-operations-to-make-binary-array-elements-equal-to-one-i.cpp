class Solution {
public:
    int minOperations(vector<int>& nums) {
        int left = 0;
        int right = 2;
        int count = 0;
        
        while(right < nums.size()){
            if(nums[left] == 0){
                count++;
                for(int i = left; i <= right; i++){
                    if(nums[i] == 0){
                        nums[i] = 1; 
                    } else {
                        nums[i] = 0;
                    } 
                }
            } 

            left++;
            right++;
        }      


        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum == nums.size()){
            return count;
        } else {
            return -1;
        }
    }
};