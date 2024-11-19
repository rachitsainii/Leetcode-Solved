class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        // Brute Force;

        //  long long ans = 0;
        //  long long sum = 0;
        //  int i = 0; 
        //  int j = k-1;
        //  int n = nums.size();
        //  unordered_set<int> s;

        //  while(j < n){
        //     for(int p = i; p <= j; p++){
        //         if(s.find(nums[p]) != s.end()){
        //             break;
        //         } else {
        //             s.insert(nums[p]);
        //         }
        //     }

        //     if(s.size() == k){
        //         for(auto i : s){
        //             sum += i;
        //         }
        //     }

        //     ans = max(ans, sum);

        //     sum = 0;
        //     s.clear();

        //     i++;
        //     j++;
            

        //  }

        //  return ans;


        long long ans = 0;
        long long sum = 0;
        unordered_set<int> s;
        int n = nums.size();
        int i = 0;
        int j = 0;

        while(j < n){
            if(s.find(nums[j]) == s.end()){
                s.insert(nums[j]);
                sum += nums[j];
                j++;

                if(j-i == k){
                    ans = max(ans, sum);
                    s.erase(nums[i]);
                    sum -= nums[i];
                    i++;
                }
            } else {
                while(nums[i] != nums[j]){
                    s.erase(nums[i]);
                    sum -= nums[i];
                    i++;
                }

                i++;
                j++;
            }
        }

        return ans;
    }
};