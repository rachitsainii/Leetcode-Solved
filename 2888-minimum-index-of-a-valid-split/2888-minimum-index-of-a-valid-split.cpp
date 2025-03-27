class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp;
        int dominant = 0, size = 0;
        for(auto i : nums){
            mp[i]++;
            if(mp[i] > nums.size() / 2){
                dominant = i;
                size = mp[i];
            }
        }

        int left = 0;
        int right = size;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == dominant){
                left++;
                right--;
            }

            if((left > (i+1) / 2) && (right >(n-1-i) / 2)){
                return i;
            }
        }

       
        return -1;
    }
};