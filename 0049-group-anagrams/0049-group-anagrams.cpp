class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> use = strs;
        unordered_map<string, vector<string>> counts;
        vector<vector<string>> ans;
        for(int i = 0; i < use.size(); i++){
            sort(use[i].begin(), use[i].end());
            counts[use[i]].push_back(strs[i]);
        }

        for(auto [key, val] : counts){
            ans.push_back(val);
        }

        return ans;
    }
    
};