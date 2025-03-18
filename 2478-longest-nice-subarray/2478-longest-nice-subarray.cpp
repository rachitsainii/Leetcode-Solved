class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int length = 1;
        int curr = 1;
        int a = nums[0];
        while(j < nums.size()){
            while((a & nums[j]) != 0){
                a ^= nums[i];
                i++;
                curr--;
            }
        
            a |= nums[j]; 
            curr++; 
            length = max(length, curr); 
            j++; 
        }

        return length;
    }
};