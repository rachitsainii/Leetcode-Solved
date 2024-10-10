class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v;

        for(int i = 0; i < n; i++){
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());
        int mini = INT_MAX;
        int ans = 0;

        for(auto i : v){
            int temp = i.first;
            int index = i.second;

            ans = max(ans, index-mini);
            mini = min(mini, index);
        }

        return ans;
    }
};