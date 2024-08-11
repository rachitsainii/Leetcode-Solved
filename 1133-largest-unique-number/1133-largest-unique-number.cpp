class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int largest = INT_MIN;
        unordered_map<int, int> counts;
        for(int i = 0; i < nums.size(); i++){
            counts[nums[i]]++;
        }

        for(auto i : counts) {
            if (i.first >= largest && i.second == 1) {
                largest = i.first;
            }
        }

        if(largest == INT_MIN){
            return -1;
        }

        return largest;
    }
};