class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() - 1;
        sort(nums.begin(), nums.end());
        for(auto i : nums){
            cout << i << " ";
        }
        cout << endl;
        return (nums[n]-1) * (nums[n-1]-1);
    }
};