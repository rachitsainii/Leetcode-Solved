class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                for(int k = j + 1; k < nums.size(); k++){
                    int triplet = (nums[i] - nums[j]) * nums[k];
                    ans = max(ans, triplet);
                }
            }
        }

        return ans;
    }
};