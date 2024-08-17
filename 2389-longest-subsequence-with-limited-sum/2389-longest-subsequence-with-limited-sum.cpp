class Solution {
public:

    int binarySearch(vector<int> &arr, int target){
        int left = 0;
        int right = arr.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(arr[mid] == target){
                return mid + 1;
            } else if (arr[mid] < target){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<int> prefix_sum = {nums[0]};
        for(int i = 1; i < nums.size(); i++){
            prefix_sum.push_back(prefix_sum.back() + nums[i]);
        }

        for(auto q : queries){
            int val = binarySearch(prefix_sum, q);
            ans.push_back(val);
        }

        return ans;
    }
};