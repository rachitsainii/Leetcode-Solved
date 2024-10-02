class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        // Create an arrat for storage of the final ans;
        vector<int> final_ans;

        if (arr.size() == 0){
            return final_ans;
        }

        // Create a copy of the original array.
        vector<int> copy(arr);

        // Create an array for storage of the ranks
        vector<int> ans = {1};

       

        // Map to link the val and it's rank;
        unordered_map<int, int> ranks;

        // Sort the copy
        sort(copy.begin(), copy.end());
       
       // Variable for ranks
        int j = 1;

        // Iterate over the copy sorted array
        for(int i = 1; i <= arr.size()-1; i++){
            // If previous is same as current, rank will be same.
            if(copy[i-1] == copy[i]){
                ans.push_back(j);
                // Increase the rank by 1.
            } else {
                j = j + 1;
                ans.push_back(j);
            }
        }
        
        // Fill the mapping for value with it's rank;
        for(int i = 0; i < arr.size(); i++){
            ranks[copy[i]] = ans[i];
        }

        // Add the values in the final ans variable based on the position in the original array.
        for(int i = 0;  i < ans.size(); i++){
            final_ans.push_back(ranks[arr[i]]);
        }


        return final_ans;
    }
};