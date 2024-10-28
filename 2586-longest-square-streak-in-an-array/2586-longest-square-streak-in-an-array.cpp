class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        unordered_set<int> s(nums.begin(), nums.end());

        sort(nums.begin(), nums.end());

        int ans = -1;
        
        for(int i = 0; i < nums.size(); i++){

            int curr_streak = 0;
            unsigned long long x = nums[i];
            while(x <= pow(10, 5)){
                if(s.find(x) != s.end()){
                    curr_streak++;
                    x = x * x;
                } else {
                    break;
                }
            }

            ans = max(ans, curr_streak);
        }
        
        if(ans == 1){
            return -1;
        }
        return ans ;
    }
};