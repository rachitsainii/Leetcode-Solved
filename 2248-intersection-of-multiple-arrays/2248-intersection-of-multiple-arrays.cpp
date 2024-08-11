class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        unordered_map<int, int> counts;
        // Time Complexity of this loop O(n*m);
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){
                counts[nums[i][j]]++;
            }
        }

        // Here the hash Map has been populated with the frequenies of all the numbers in all the arrays.
        // Now, iterate over the hash map.

        for(auto i : counts){
            if(i.second == int(nums.size())){
                ans.push_back(i.first);
            }
        }

        // Sort the ans vector to get the final answer.
        sort(ans.begin(), ans.end());

        return ans;
    }
};