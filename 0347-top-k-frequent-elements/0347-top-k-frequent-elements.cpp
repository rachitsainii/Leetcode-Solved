class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for(auto i : nums){
            counts[i]++;
        }

        priority_queue<pair<int, int>> heap;
        for(auto [key, val] : counts){
           heap.push(make_pair(-1*val, key));
           if(heap.size() > k){
            heap.pop();
           }
        }

        vector<int> ans;
        while(heap.size() > 0){
            ans.push_back((heap.top().second));
            heap.pop();
        }

        return ans;
    }
};