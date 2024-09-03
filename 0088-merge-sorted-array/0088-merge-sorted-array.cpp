class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m;
        int p2 = 0;
       for(int i = p1; i < nums1.size(); i++){
        nums1[i] = nums2[p2];
        p2++;
       }
        sort(nums1.begin(), nums1.end());
       
    }
};