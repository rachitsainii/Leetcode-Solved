class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

        // Brute Force Solution: TLE for the last test case


        // vector<bool> ans;
        // for(auto i : queries){
        //    int start = i[0];
        //    int end = i[1];

        //     int flag = 0;
        //     while(start + 1 <= end){
        //         if((nums[start] % 2 == 0 && nums[start+1] % 2 == 1) || (nums[start] % 2 == 1 && nums[start+1] % 2 == 0)){
        //             start++;
        //         } else {
        //             flag = 1;
        //             break;
        //         }
        //     }

        //     if(flag == 1){
        //         ans.push_back(false);
        //     } else {
        //         ans.push_back(true);
        //     }
        // }

        // return ans;


        // Optimized Solution using Cumulative Sum 
        vector<bool> ans;
        int j = 0;
        vector<int> cum_sum = {0};
        for(int i = 1; i < nums.size(); i++){
            if((nums[i] % 2 == 0 && nums[i-1] % 2 == 1) || (nums[i] % 2 == 1 && nums[i-1] % 2 == 0)){
                cum_sum.push_back(cum_sum[j]);
            } else {
                cum_sum.push_back(cum_sum[j] + 1);
            }

            j++;
        }

        
        // for (auto i : cum_sum){
        //     cout << i << " ";
        // }

        for(auto i : queries){
            int start = i[0];
            int end = i[1];

            if(cum_sum[end] - cum_sum[start] == 0){
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }


        return ans;

    }
};