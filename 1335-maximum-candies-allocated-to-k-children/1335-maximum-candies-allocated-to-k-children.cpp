class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        sort(candies.begin(), candies.end());
        long long sum = 0;
        
        for(auto candy : candies){
            sum += candy;
        }
        if(sum < k){
            return 0;
        }

        long long left = 1;
        long long right = sum / k;

        while(left <= right){
            long long mid = left + (right - left) / 2;
            if(check(mid, candies, k)){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

         return right;
    }

     bool check(int mid, vector<int> &candies, long long k){
        long long count = 0;
        for(auto candy : candies){
            count += candy/mid;
        }

        return count >= k;
    }
};