#include<bits/stdc++.h>

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // Sorting Approach O(nlogn)
       /* vector<int> ans;
        int i = 0;
        int j = 0;
        int val = 0;
        for (i ; i < nums.size(); i++){
            val = nums[i] * nums[i];
            ans.push_back(val);
        }
        sort(ans.begin(), ans.end());
        return ans; */

        // Two Pointer Approach
        int n = nums.size();
        vector<int> ans(n);
        int left = 0;
        int right = n-1;
        int square = 0;
        for(int i = n-1; i >= 0; i--) {
            if(abs(nums[left]) < abs(nums[right])){
                square = nums[right] * nums[right];
                right--;
            } else {
                square = nums[left] * nums[left];
                left++;
            }
            ans[i] = square;
        }

        return ans;
    }
};