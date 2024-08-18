class Solution {
public:

    int maximumCount(vector<int>& nums) {
        int s = nums.size();
        int count_p = 0;
        int count_n = 0;
        for(int i = 0; i < s; i++){
            if(nums[i] > 0){
                count_p++;
            }else if(nums[i] < 0){
                count_n++;
            }else {
                continue;
            }
        }

        return max(count_p, count_n);

    }
};