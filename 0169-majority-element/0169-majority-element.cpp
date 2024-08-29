class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        for(auto i : nums){
            counts[i]++;
        }

        int n = nums.size();
        int majority = 0;
        for(auto i : counts){
            if(counts[i.first] > (n / 2)){
                majority = i.first;
            } else {
                continue;
            }
        }

        for(auto i : counts){
            cout << i.first << ":" << i.second << endl;
        }

        return majority;
    }
};