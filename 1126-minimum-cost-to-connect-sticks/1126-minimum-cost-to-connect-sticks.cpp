class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> minHeap(sticks.begin(), sticks.end());
        // int cost = 0;
        int ans = 0;
        while(minHeap.size() > 1){
        int smallest = minHeap.top();
        minHeap.pop();
        int secondSmallest = minHeap.top();
        minHeap.pop();
        int cost = smallest + secondSmallest;
        ans += cost;
        minHeap.push(cost);
       }

        return ans;
    }
};