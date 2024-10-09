class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> heap;
        for(int i = 0; i < points.size(); i++){
            double distance = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            heap.push(make_pair(distance, points[i]));
            if(heap.size() > k){
                heap.pop();
            }
        }

        vector<vector<int>> ans;
        while(heap.size() > 0){
            ans.push_back(heap.top().second);
            heap.pop();
        }

        return ans;

    }
};