class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        // // Brute Force
        // int ans = 0;
        //    for(int i = 0; i < values.size(); i++){
        //         for(int j = i + 1; j < values.size(); j++){
        //             int x = (values[i] + i) + (values[j] - j);
        //             ans = max(ans, x);
        //         }
        //    }

        // return ans;

        // Using Max Heap

        int ans = 0;
        priority_queue<int> pq;
        pq.push(values[0] + 0);
        for(int j = 1; j < values.size(); j++){
            int x = pq.top() + (values[j] - j);
            ans = max(ans, x);
            pq.push(values[j] + j);

        }

        return ans;
    }
};