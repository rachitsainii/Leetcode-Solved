class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> min_heap;;
        for(auto i : intervals){
            int start = i[0];
            int end = i[1];
            if(!min_heap.empty() && min_heap.top() < start){
                min_heap.pop();
            }

            min_heap.push(end);
        }

        return min_heap.size();
    }
};