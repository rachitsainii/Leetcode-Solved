class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xorOfNums1 = nums1[0];
        int xorOfNums2 = nums2[0];

        for(int i = 1; i < nums1.size(); i++){
            xorOfNums1 ^= nums1[i];
        }

        for(int i = 1; i < nums2.size(); i++){
            xorOfNums2 ^= nums2[i];
        }

        int m = nums1.size() ;
        int n = nums2.size();

        int result1 = xorOfNums2;
        int result2 = xorOfNums1;

        for(int i = 1; i < m; i++){
            result1 ^= xorOfNums2;
        }

         for(int i = 1; i < n; i++){
            result2 ^= xorOfNums1;
        }

        return result1 ^ result2;

    }
};