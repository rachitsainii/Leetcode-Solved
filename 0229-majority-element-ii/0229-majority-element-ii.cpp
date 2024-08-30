class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        vector<int> ans;
        int n = nums.size();
        for(auto i : nums){
            count[i]++;
        }

        for(auto i : count){
            if(i.second > n/3){
                ans.push_back(i.first);
            }
        }

        for(auto i : count){
            cout << i.first << ":" << i.second << endl;
        }



        return ans;
    }
};