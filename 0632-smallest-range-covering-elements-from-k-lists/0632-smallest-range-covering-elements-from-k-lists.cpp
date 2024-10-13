class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        vector<pair<int, int>> a;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){
                a.push_back(make_pair(nums[i][j], i));
            }
        }

        sort(a.begin(), a.end());

        int total_seen = 0;
        int id = nums.size();
        vector<int> mp(id, 0);
        int mini = INT_MAX;
        int j = 0;
        for(int i = 0; i < a.size(); i++){
            mp[a[i].second]++;
            if(mp[a[i].second] == 1){
                total_seen++;
            }

            if(total_seen == id){
                if(a[i].first - a[j].first+1 < mini){
                    mini = a[i].first - a[j].first + 1;
                    ans = {a[j].first, a[i].first};
                }
            }

            if(total_seen == id){
                while(total_seen == id){
                    if(mp[a[j].second] > 1){
                        mp[a[j].second]--;
                        j++;
                    } else {
                        break;
                    }
                }

                if(a[i].first - a[j].first + 1 < mini){
                    mini = a[i].first - a[j].first + 1;
                    ans = {a[j].first, a[i].first};
                    
                }
            }
        }

        return ans;
    }
};