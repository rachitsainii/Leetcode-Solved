class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Solved Using Two Pointer Approach.
            // 1. Created a copy of the nums array called copy. 
            // 2. Sorted the copy array. (Ologn)
            // 3. Applied two pointer method. 
            // 4. Got the two elements in the copy array whose sum is equal to target.
            // 5. Applied linear search in the nums array to get the required indices of the elements (O(n)).
            // Total time complexity (Onlogn)
            // Space O(n);
            // Better method is using a Hashmap.
        vector<int> copy(nums);
        vector<int> ans;
        sort(copy.begin(), copy.end());
        int left = 0;
        int right = copy.size() - 1;
        int ele1 = 0;
        int ele2 = 0;
        while(left < right) {
            int sum = copy[left] + copy[right];
            if(sum < target) {
                left++;
            } else if(sum > target) {
                right--;
            } else {
                ele1 = copy[left];
                ele2 = copy[right];
                break;
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == ele1 || nums[i] == ele2) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};