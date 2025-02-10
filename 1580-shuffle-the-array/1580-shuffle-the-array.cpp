class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int p1 = 0; 
        int p2 = n;
        vector<int> ans;
        while(p2 < 2 * n){
            ans.push_back(nums[p1]);
            ans.push_back(nums[p2]);
            p1++;
            p2++;
        }

        return ans;
    }
};