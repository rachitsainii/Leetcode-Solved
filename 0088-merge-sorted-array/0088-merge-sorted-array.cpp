class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(nums1);
        vector<int> ans;
        while(n!=0){
            temp.pop_back();
            n--;
        }
        int first = 0;
        int second = 0;
        while(first < temp.size() && second < nums2.size()){
            if(temp[first] <= nums2[second]){
                ans.push_back(temp[first]);
                first++;
            } else {
                ans.push_back(nums2[second]);
                second++;
            }
        }

        while(first < temp.size()){
            ans.push_back(temp[first]);
            first++;
        }

        while(second < nums2.size()){
            ans.push_back(nums2[second]);
            second++;
        }

        nums1 = ans;
    }
};