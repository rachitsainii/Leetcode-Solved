class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<pair<int, int>> v(n);

        for(int i = 0; i < nums.size(); i++){
            int x = nums[i] - k;
            int y = nums[i] + k;
            v[i] = {x,y};
        }

        queue<int> q;
        int maxBeauty = 0;
        for(pair<int, int> i : v){
            while(!q.empty() && q.front() < i.first){
                q.pop();
            }

            q.push(i.second);

            maxBeauty = max(maxBeauty, (int)q.size());
        }

        
        return maxBeauty;
    }
};