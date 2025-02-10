class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int> ans;
        priority_queue<pair<float, pair<int, int>>, vector<pair<float, pair<int, int>>>, greater<pair<float, pair<int, int>>>> pq;

        for(int i = 0; i < arr.size(); i++){
            for(int j = i + 1; j < arr.size(); j++){
                pq.push({double(arr[i]) / double(arr[j]),{arr[i], arr[j]}});
            }
        }

        while(k > 1){
            pq.pop();
            k--;
        }

        ans.push_back(pq.top().second.first);
        ans.push_back(pq.top().second.second);

        return ans;
    }
};