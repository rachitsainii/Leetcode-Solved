class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> counts;
        for(int i = 0; i < nums.size(); i++){
            counts[nums[i]]++;
        }

        long long  sum = 0;
        for(auto [key, val] : counts){
            if(val == 1){
                sum += key;
            } else {
                continue;
            }
        }

        return sum;
    }
};