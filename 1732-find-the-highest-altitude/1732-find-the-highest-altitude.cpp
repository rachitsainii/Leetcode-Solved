class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        // Solved using Prefix Sum
        vector<int> prefix_sum = {0, gain[0]};
        for (int i = 1; i < gain.size(); i++){
            prefix_sum.push_back(prefix_sum.back() + gain[i]);
        }

        sort(prefix_sum.begin(), prefix_sum.end());

        return prefix_sum[prefix_sum.size()-1];

    }
};