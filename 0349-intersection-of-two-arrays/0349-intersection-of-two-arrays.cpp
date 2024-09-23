class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> array1(nums1.begin(), nums1.end());
        unordered_set<int> intersection;
        vector<int> ans;
        for(auto i : nums2){
            if(array1.find(i) != array1.end()){
                intersection.insert(i);
            }
        }

        for(auto i : intersection){
            ans.push_back(i);
        }

        return ans;
    }
};