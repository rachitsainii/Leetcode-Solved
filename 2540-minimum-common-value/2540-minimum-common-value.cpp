class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

       /* // 1. Brute Force
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    return nums1[i];
                }
            }
        }

        return -1; */


        int leftNums1 = 0;
        int rightNums1 = nums1.size() - 1;
        int leftNums2 = 0;
        int rightNums2 = nums2.size() - 1;
        while(leftNums1 <= rightNums1 && leftNums2 <= rightNums2){
            if(nums1[leftNums1] == nums2[leftNums2]){
                return nums1[leftNums1];
            }

            if(nums1[leftNums1] < nums2[leftNums2]){
                leftNums1++;
            } else {
                leftNums2++;
            }

        }

        return -1;
    }
};