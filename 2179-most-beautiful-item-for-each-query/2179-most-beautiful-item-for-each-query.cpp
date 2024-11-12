class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans;
        vector<pair<int, int>> p;
        
        for(int i = 0; i < items.size(); i++){
            pair<int, int> x;
            x.first = items[i][0];
            x.second = items[i][1];
            p.push_back(x);
        }

        sort(p.begin(), p.end());

        // Update each price to hold the max beauty up to that price
        for (int i = 1; i < p.size(); i++) {
            p[i].second = max(p[i].second, p[i - 1].second);
        }

        for( auto query : queries){
            int sol = 0;
            int start = 0;
            int end = p.size() - 1;
            while(start <= end){
                int mid = start + (end - start) / 2;
                if(p[mid].first > query){
                    end = mid - 1;
                } else {
                    sol = max(sol, p[mid].second);
                    start = mid + 1;

                }
            }

            ans.push_back(sol);

        }

        return ans;
    }
};