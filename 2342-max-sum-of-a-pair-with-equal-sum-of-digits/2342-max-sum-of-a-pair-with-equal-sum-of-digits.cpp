class Solution {
public:
    int maximumSum(vector<int>& nums) {
       vector<int> copy(nums);
       int sum = 0;
        unordered_map<int, vector<int>> groups;
        for(int i = 0; i < copy.size(); i++){
            sum = 0;
             while(copy[i] > 0) {
                int digit = copy[i] % 10;
                int quo = copy[i] / 10;
                sum += digit;
                copy[i] = quo;
             }
            groups[sum].push_back(nums[i]);
        }

        int ans = INT_MIN;
        for(auto [key, val] : groups){
            if(val.size() > 1){
                ans = max(ans, val[0] + val[1]);
            }
        }

        if(ans == INT_MIN) {
            return -1;
        }
        
        return ans;

    } 
};