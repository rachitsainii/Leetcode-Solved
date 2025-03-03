class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int p1 = 0;
        int p2 = 0;
        while(p1 < nums1.size() && p2 < nums2.size()){
            if(nums1[p1][0] == nums2[p2][0]){
                int id = nums1[p1][0];
                int val = nums1[p1][1] + nums2[p2][1];
                ans.push_back({id, val});
                p1++;
                p2++;
            } else if(nums1[p1][0] < nums2[p2][0]){
                ans.push_back({nums1[p1][0], nums1[p1][1]});
                p1++;
            } else {
                ans.push_back({nums2[p2][0], nums2[p2][1]});
                p2++;
            }
        }

        while(p1 < nums1.size()){
            ans.push_back({nums1[p1][0], nums1[p1][1]});
            p1++;
        }

        while(p2 < nums2.size()){
            ans.push_back({nums2[p2][0], nums2[p2][1]});
            p2++;
        }

        return ans;
    }
};