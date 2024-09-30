class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0;
        int p2 = 0;
        vector<int> merged;
        while(p1 < nums1.size() && p2 < nums2.size()){
            if(nums1[p1] <= nums2[p2]){
                merged.push_back(nums1[p1]);
                p1++;
            } else{
                merged.push_back(nums2[p2]);
                p2++;
            }
        }

        while(p1 < nums1.size()){
             merged.push_back(nums1[p1]);
            p1++;
        }

        while(p2 < nums2.size()){
             merged.push_back(nums2[p2]);
            p2++;
        }


        for(auto i: merged){
            cout << i << " ";
        }

        cout << endl;


        int size = merged.size();

        cout << size/2 - 1 << endl;
        if(size % 2 != 0){
            return double (merged[(size/2)]);
        } else{
            return double((double(merged[size/2]) + merged[(size/2)-1]) / 2);
        }
    }
};