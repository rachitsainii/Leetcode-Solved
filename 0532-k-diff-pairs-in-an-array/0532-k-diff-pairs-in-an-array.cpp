class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        set<pair<int,int>> s;
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(abs(nums[i] - nums[j]) == k){
                    if(nums[i] <= nums[j]){
                        s.insert({nums[i], nums[j]});
                    } else {
                        s.insert({nums[j], nums[i]});
                    }
                    
                }
            }
        }

        for(auto i : s){
            cout << i.first << " " << i.second << endl;
        }

        return s.size();
    }
};