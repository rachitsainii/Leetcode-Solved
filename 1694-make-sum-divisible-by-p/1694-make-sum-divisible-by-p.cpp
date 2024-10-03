class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int ans = nums.size();  // Initialize ans to the size of the array initially
        unsigned long sum = 0;
        int remainder = 0;
        
        // Calculate the total sum of the array
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        // If the sum is already divisible by p, return 0
        if (sum % p == 0) {
            return 0;
        } else {
            remainder = sum % p;
        }

        // Track prefix sums mod p
        unordered_map<int, int> prefixMap;
        prefixMap[0] = -1;  // Initialize with prefix sum 0 at index -1
        long unsigned prefixSum = 0;

        // Traverse through the array
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int mod = prefixSum % p;
            
            // Check if there's a prefix sum that matches the remainder we need to remove
            int target = (mod - remainder + p) % p;
            if (prefixMap.find(target) != prefixMap.end()) {
                ans = min(ans, i - prefixMap[target]);
            }
            
            // Store the current prefix sum mod p with its index
            prefixMap[mod] = i;
        }

        // If no valid subarray was found, return -1, else return ans
        return (ans == nums.size()) ? -1 : ans;
    }
};
