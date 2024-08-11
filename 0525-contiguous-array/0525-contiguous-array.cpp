class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        int maxLen = 0;
        unordered_map <int, int> counts;
        counts[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            sum += (nums[i] == 1 ? 1 : -1);
            if(counts.find(sum) != counts.end()){
                maxLen = max(maxLen, i - counts[sum]);
            } else {
                counts[sum] = i;
            }
        }

        return maxLen;
    }
};