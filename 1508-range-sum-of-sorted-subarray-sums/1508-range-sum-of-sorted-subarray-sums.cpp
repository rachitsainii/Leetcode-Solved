class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // int r = 1;
        // int sum = 0;
        // vector<int> prefix_sum = {nums[0]};
        vector<int> allSums;
        unsigned long long  finalSum = 0;
        // for(r = 1; r < n; r++){
        //     prefix_sum.push_back(prefix_sum.back()+ nums[r]);
        //     allSums.push_back(prefix_sum.back()+ nums[r]);
        // }
        
        // for(int i = 1; i < prefix_sum.size(); i++){
        //     sum = prefix_sum[i] - prefix_sum[i-1];
        //     allSums.push-back(sum);
        // }

        for(int i = 0; i < nums.size(); i++){
            unsigned long long sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];
                allSums.push_back(sum);
            }
        }

        sort(allSums.begin(), allSums.end());

        for(int it = left-1; it < right ; it++){
            finalSum += allSums[it];
        }
        for(auto i : allSums){
            cout << i << endl;
        }
        return finalSum  % 1000000007;
    }
};