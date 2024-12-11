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

        deque<pair<int, int>> deq;
        int maxBeauty = 0;
        for(pair<int, int> i : v){
            while(!deq.empty() && deq.front().second < i.first){
                deq.pop_front();
            }

            deq.push_back(i);

            maxBeauty = max(maxBeauty, (int)deq.size());
        }

        
        return maxBeauty;
    }
};