class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>> &intervals){
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        result.push_back(intervals[0]);

        for(int i = 1; i < n; i ++){
            if(intervals[i][0] < result.back()[1]){
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x;
        vector<vector<int>> y;

        for(auto rectangle : rectangles){
            x.push_back({rectangle[0], rectangle[2]});
            y.push_back({rectangle[1], rectangle[3]});
        }


        vector<vector<int>> result1 = merge(x);
        if(result1.size() >= 3){
            return true;
        }
        vector<vector<int>> result2 = merge(y);

        return result2.size() >= 3;
    }
};