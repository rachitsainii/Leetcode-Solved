class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int ans = 1;
        sort(nums.begin(), nums.end());
        int start = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - start > k){
                ans++;
                start = nums[i];
            } 
        }

        return ans;
    }
};