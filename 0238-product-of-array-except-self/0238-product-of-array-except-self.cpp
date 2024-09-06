class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count_zeros = 0;
        int total_product = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                count_zeros++;
            }
            total_product *= nums[i];
        } 

        vector<int> ans;
        if(count_zeros == 0){
            for(int i = 0; i < nums.size(); i++){
                ans.push_back(total_product / nums[i]);
            }
        } else if(count_zeros == 1){
            total_product = 0;
            int product_without_zero = 1;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 0){
                    continue;
                } else {
                    product_without_zero *= nums[i];
                }
            }

            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 0){
                    ans.push_back(product_without_zero);
                } else {
                    ans.push_back(total_product);
                }
            }
        } else {
            for(int i = 0; i < nums.size(); i++){
                ans.push_back(0);
            }
        }

        return ans;
    }
};