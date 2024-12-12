class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        int n = grid.size();
        unordered_set<int> s;
        for(int i = 1; i <= n * n; i++){
            s.insert(i);
        }

       for(auto i : grid){
        for(auto j : i){
            if(s.find(j) != s.end()){
                s.erase(j);
            } else {
                ans.push_back(j);
            }
        }
       }

       for(auto i : s){
        ans.push_back(i);
       }

       return ans;
    }
};