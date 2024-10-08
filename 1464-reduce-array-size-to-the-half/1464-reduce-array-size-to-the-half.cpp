class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> counts;
        vector<pair<int, int>> vp;
        pair<int, int> p;
        
        for(int i = 0; i < arr.size(); i++){
            counts[arr[i]]++;
        }

        for(auto [key, val] : counts){
            p.first = key;
            p.second = val;
            vp.push_back(p);
        }

        sort(vp.begin(), vp.end(), [](const pair<int, int> p1, const pair<int, int> p2) {return  p1.second > p2.second;});

        int total = arr.size();
        int ans = 0;
        int it = 0;

        while(total > arr.size() / 2 && it < vp.size()){
            ans++;
            total -= vp[it].second;
            it++;
        }    

        return ans;
    }
};