class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int sIA = 1;
        int maxSIA = 1;
        int sDA = 1;
        int maxSDA = 1;


        for(int i = 0; i < n-1; i++){
           if(nums[i] < nums[i+1]){
            sIA++;
           } else {
            maxSIA = max(maxSIA, sIA);
            sIA = 1;
           }
        }

        maxSIA = max(maxSIA, sIA);

        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1]){
                sDA++;
            } else {
            maxSDA = max(maxSDA, sDA);
            sDA = 1;
           }
        } 

        maxSDA = max(maxSDA, sDA);

        return max(maxSIA, maxSDA);
    }
};