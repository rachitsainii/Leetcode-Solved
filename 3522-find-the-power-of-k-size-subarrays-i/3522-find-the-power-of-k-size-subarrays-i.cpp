class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int left = 0;
        int right = left + k - 1;
        while(right < nums.size()){
            int flag = 0;
            for(int i = left; i < right; i++){
                if(nums[i] >= nums[i + 1] || nums[i] + 1 != nums[i + 1]){
                    ans.push_back(-1);
                    flag = 1;
                    break;
                } 
            } 
            if(flag == 0){
                ans.push_back(nums[right]);

            }
            left++;
            right++;
        }

        return ans;
    }
};