class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller;
        vector<int> equal;
        vector<int> greater;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == pivot){
                equal.push_back(pivot);
            } else if(nums[i] < pivot){
                smaller.push_back(nums[i]);
            } else {
                greater.push_back(nums[i]);
            }
        }

        smaller.insert(smaller.end(), equal.begin(), equal.end());
        smaller.insert(smaller.end(), greater.begin(), greater.end());

        return smaller;
    }
};