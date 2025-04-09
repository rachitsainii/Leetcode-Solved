class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Step 1: If any number is less than k, it's impossible
        for (int num : nums) {
            if (num < k) return -1;
        }

        // Step 2: Collect unique values > k
        unordered_set<int> s;
        for (int num : nums) {
            if (num > k) {
                s.insert(num);
            }
        }

        // Step 3: The number of operations = size of the set
        return s.size();
    }
};
