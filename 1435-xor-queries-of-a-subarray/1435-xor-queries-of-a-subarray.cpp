class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // Brute Force
        // vector<int> ans;
        // for(int i = 0; i < queries.size(); i++){
        //     int left = queries[i][0];
        //     int right = queries[i][1];
        //     int val = arr[left];
        //     for(int j = left + 1; j <= right; j++){
        //         val = val ^ arr[j];

        //     }
        //     ans.push_back(val);
        // }

        // return ans;

        // Using Prefix Sum
        int n = arr.size();
        vector<int> prefix(n);
        vector<int> ans(queries.size());

        // Fill in the prefix_sum
        prefix[0] = arr[0];
        for(int i = 1; i < arr.size(); i++){
            prefix[i] = prefix[i-1] ^ arr[i];
        }

        for(auto i : prefix){
            cout << i << endl;
        }

        for(int i = 0; i < queries.size(); i++){
            int left = queries[i][0];
            int right = queries[i][1];
            if(left == 0){
                ans[i] = prefix[right];
            } else{
                ans[i] = prefix[right] ^ prefix[left-1];
            }
        } 

        return ans;
    }
};