class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int n = nums.size();

        vector<int> ans(n);
        vector<pair<int, int>> temp;

        for(int i = 0 ; i < n; i++){
            pq.push({nums[i], i});
        }


        while(k--){
            int val = pq.top().first;
            int pos = pq.top().second;
            pq.pop();
            int new_val = val * multiplier;
            pq.push({new_val, pos});
        }

        while(!pq.empty()){
            int val = pq.top().first;
            int pos = pq.top().second;
            pq.pop();
            temp.push_back({pos, val});
        }

        sort(temp.begin(), temp.end());

        for(int i = 0; i < n; i++){
            ans[i] = temp[i].second;
        }

        
        return ans;
    }
};