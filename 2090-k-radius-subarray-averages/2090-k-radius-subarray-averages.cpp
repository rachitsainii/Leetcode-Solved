class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // Single element case : k = 0
        if(k == 0) {
            return nums;
        }

        int windowSize = (2*k)+1;
        int n = nums.size();
        vector<int> averages(n, -1);

        if (windowSize > n) {
            return averages;
        }

        // Generate Prefix Sum Array
        vector<long long int> prefix_sum = {nums[0]};
        for(int i = 0; i < n; i++){
            prefix_sum.push_back(prefix_sum.back() + nums[i]);
        }

        for(int i = k; i < (n-k); i++) {
            int leftBound = i - k;
            int rightBound = i + k;
            long long subArraySum = prefix_sum[rightBound + 1] - prefix_sum[leftBound];
            long long avg = subArraySum / windowSize;
            averages[i] = avg;
        }

        return averages;
    }
};