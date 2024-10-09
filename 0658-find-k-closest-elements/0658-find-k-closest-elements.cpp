class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int, int>> heap;

        for(auto i : arr){
            int diff = abs(x - i);
            heap.push(make_pair(diff, i));
            if(heap.size() > k){
                heap.pop();
            }
        }

        while(heap.size() > 0){
            ans.push_back(heap.top().second);
            heap.pop();
        }

        sort(ans.begin(), ans.end());
        return ans;


    }
};