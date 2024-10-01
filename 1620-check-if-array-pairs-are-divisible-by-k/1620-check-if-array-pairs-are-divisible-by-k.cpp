class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        // Create a mapping for all the remainders with their counts
        unordered_map<int, int> remainderCount;

        for(auto num : arr){
            int remainder = ((num % k) + k) % k; // Handle negative numbers
            remainderCount[remainder]++;
        }

        // O/P : 0->2, 1->2, 2->2, 3->2, 4->2
        // for(auto [key, val] : remainderCount){
        //     cout << key << ":" << val << endl;
        // }

        // For each number in the array
        for(auto num : arr){
            // Calculate the remainder
            int remainder = ((num % k ) + k) % k;
            
            // If the remainder is 0, then
            if(remainder == 0){
                // Check if the count of numbers having 0 as remainder is even
                // If not return false;
                if(remainderCount[remainder] % 2 != 0){
                    return false;
                }
            // If the remainder is not 0, then check if for the number k - remainder.
            } else {
                if(remainderCount[remainder] != remainderCount[k - remainder]){
                    return false;
                }
            }
        }

        // Finally return true;
        return true;
    }
};