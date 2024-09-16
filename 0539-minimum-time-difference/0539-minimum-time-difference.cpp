class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // Convert time to minutes
        vector<int> minutes(timePoints.size());
        for(int i = 0; i < timePoints.size(); i++){
            // int pos = timePoints[i].find(':');
            minutes[i] = stoi(timePoints[i].substr(0,2)) * 60 + stoi(timePoints[i].substr(3,timePoints[i].size()));
        }

        // Sort the minutes array
        sort(minutes.begin(), minutes.end());

        int min_dif = 1439;
        for(int i = 1; i < minutes.size(); i++){
            if((minutes[i] - minutes[i-1]) < min_dif) {
                min_dif = minutes[i] - minutes[i-1];
            }
        }

        for(auto i : minutes){
            cout << i << " " ;
        }

        if(minutes[0] + 1440 - minutes[minutes.size()-1] < min_dif){
            min_dif = minutes[0] + 1440 - minutes[minutes.size()-1];
        }

        return min_dif;
    }
};