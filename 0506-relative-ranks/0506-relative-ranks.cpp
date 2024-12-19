class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        if(score.size() == 1){
            return {"Gold Medal"};
        } 
        vector<pair<int, int>> v;
        vector<pair<int,string>> p;
        vector<string> ans;
        for(int i = 0; i < score.size(); i++){
            v.push_back({score[i], i});
        }

        sort(v.begin(), v.end(), greater<pair<int, int>>());

        p.push_back({v[0].second, "Gold Medal"});
        if(v.size() >= 2){
            p.push_back({v[1].second, "Silver Medal"});
        }

        if(v.size() >= 3){
            p.push_back({v[2].second, "Bronze Medal"});

             for(int i = 3; i < v.size(); i++){
                p.push_back({v[i].second, to_string(i+1)});
            }

        }
        

       

        sort(p.begin(), p.end());

        for(auto i : p){
            ans.push_back(i.second);
        }

        return ans;
    }
};