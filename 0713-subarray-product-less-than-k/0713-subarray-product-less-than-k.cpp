class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int product = 1;
        int ans = 0;
        if(k <= 1){
            return 0;
        }
        for (right = 0; right < nums.size(); right++){
            product *= nums[right];

            while(product >= k) {
                product /= nums[left];
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};