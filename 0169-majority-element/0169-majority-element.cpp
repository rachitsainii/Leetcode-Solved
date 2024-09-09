class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> counts;
        for(auto i : nums){
            counts[i]++;
        }
        int ans = 0;
        for(auto [key, value] : counts){
            if(counts[key] > n / 2){
                ans = key;
            }
        }

        for(auto [key, value] : counts){
            cout << key << " " << value << endl;
        }

        return ans;
    }
};