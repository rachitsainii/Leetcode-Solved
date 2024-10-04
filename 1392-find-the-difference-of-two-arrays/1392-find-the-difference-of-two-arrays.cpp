class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> ans1;
        vector<int> ans2;
        vector<vector<int>> final_ans;

        for(auto i : set1){
            if(set2.find(i) == set2.end()){
                ans1.push_back(i);
            }
        }

        for(auto i : set2){
            if(set1.find(i) == set1.end()){
                ans2.push_back(i);
            }
        }

        final_ans.push_back(ans1);
        final_ans.push_back(ans2);

        return final_ans;

    }
};