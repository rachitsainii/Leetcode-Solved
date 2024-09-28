class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> seen;
        int partitions = 1;  // Start with 1 partition

        for (char c : s) {
            if (seen.find(c) != seen.end()) {
                // If the character is already seen, we need a new partition
                partitions++;
                seen.clear();  // Clear the set for the new partition
            }
            seen.insert(c);  // Add character to the set
        }

        return partitions;
    }
};
