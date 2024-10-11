class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int target = times[targetFriend][0];

        sort(times.begin(), times.end());
        int n = times.size();

        // Priority Queue for available chairs
        priority_queue<int, vector<int> , greater<int>> chairs;

        for(int i = 0; i < n; i++){
            chairs.push(i);
        }

        // Priority queue for departure time
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > leaving;

        for(auto v : times){
            int arrival = v[0], dep = v[1];
            while(!leaving.empty() && leaving.top().first <= arrival){
                pair<int, int> p = leaving.top();
                leaving.pop();
                chairs.push(p.second);
            }

            int chair = chairs.top();
            chairs.pop();
            leaving.push({dep, chair});
            if(arrival == target){
                return chair;
            }
        }

        return -1;

        
    }
};