class Solution {
public:

    int binarySearch(vector<int> &nums, double target){
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        int m = potions.size();
        for(double spell : spells){
            int i = binarySearch(potions, success / spell);
            ans.push_back(m - i);
        }

        return ans;
    }
};