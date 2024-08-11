class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans = {{}, {}};
        unordered_map<int, int> counts;
        for(int i = 0; i < matches.size(); i++){
            for(int j = 0; j < matches[i].size(); j++){
                counts[matches[i][j]];
            }
        }
    
        for(int i = 0; i < matches.size(); i++){
            if(counts.find(matches[i][1]) != counts.end()){
                counts[matches[i][1]]++;
            }
        }
    
        for( auto i : counts) {
            if(i.second == 0){
                ans[0].push_back(i.first);
            } else if(i.second == 1){
                ans[1].push_back(i.first);
            }
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());

        return ans;
    }
};