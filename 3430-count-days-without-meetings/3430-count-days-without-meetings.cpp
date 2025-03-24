class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<pair<int, int>> p;
        for(int i = 0; i < meetings.size(); i++){
            p.push_back({meetings[i][0], meetings[i][1]});
        }


        sort(p.begin(), p.end());

        int left = p[0].first;
        int right = p[0].second;
        int occupied = 0;
        for(int i = 1; i < p.size(); i++){
            if(p[i].first <= right && p[i].second <= right){
                continue;
            } else if (p[i].first <= right && p[i].second > right){
                right = p[i].second;
            } else if(p[i].first > right && p[i].second > right) {
                occupied += (right - left + 1);
                left = p[i].first;
                right = p[i].second;
            }
        }

        occupied += (right - left + 1);

        return days - occupied;
    }
};