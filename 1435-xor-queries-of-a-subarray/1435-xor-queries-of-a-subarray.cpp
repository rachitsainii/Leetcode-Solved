class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            int left = queries[i][0];
            int right = queries[i][1];
            int val = arr[left];
            for(int j = left + 1; j <= right; j++){
                val = val ^ arr[j];

            }
            ans.push_back(val);
        }

        return ans;
    }
};