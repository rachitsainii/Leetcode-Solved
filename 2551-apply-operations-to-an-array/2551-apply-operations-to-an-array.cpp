class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] = nums[i] * 2;
                nums[i+1] = 0;
            } else {
                continue;
            }
        }

        int z = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                z++;
            } else {
                ans.push_back(nums[i]);
            }
        }

        while(z--){
            ans.push_back(0);
        }

        return ans;
    }
};