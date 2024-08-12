class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> counts;
        for(int i = 0; i < nums.size(); i++){
            counts[nums[i]]++;
        }

        for(auto [key, val] : counts){
            if (val >= 2){ 
                return true;
            } 
        }

        return false;
    }
};