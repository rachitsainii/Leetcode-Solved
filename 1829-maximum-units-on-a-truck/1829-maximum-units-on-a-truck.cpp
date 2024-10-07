class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        long long ans = 0;
        vector<pair<int, int>> values;
        
        for(int i = 0; i < boxTypes.size(); i++){
            pair<int, int> value;
            value.first = boxTypes[i][0];
            value.second = boxTypes[i][1];
            values.push_back(value);
        }

        sort(values.begin(), values.end(), [](const pair<int, int> j, const pair<int, int> k){return j.second > k.second;});

        long long count = 0;
        int it = 0;
        while(count <= truckSize && it < values.size()){
            if(count + values[it].first > truckSize){
                int diff = truckSize - count;
                count += diff;
                ans += static_cast<long long>(diff) * values[it].second;
                break;
            }
            count += values[it].first;
            ans += static_cast<long long>(values[it].first) * values[it].second;
            it++;
            cout << count << " " << ans << endl;
        }

        return static_cast<int>(ans);
    }
};