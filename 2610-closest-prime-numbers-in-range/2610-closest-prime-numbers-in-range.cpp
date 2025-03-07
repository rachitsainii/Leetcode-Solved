class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans = {-1, -1};
        vector<int> primes;
        int flag = 1;
        for(int i = left; i <= right; i++){
            flag = 1;
            if(i == 1){
                continue;
            }
            for(int j = 2; j <= sqrt(i); j++){
                if(i % j == 0){
                    flag = 0;
                    break;
                } 
            }

            if(flag == 1){
                primes.push_back(i);
            }
        }

        int diff = INT_MAX;
        for(int i = 1; i < primes.size(); i++){
            if(primes[i] - primes[i-1] < diff){
                diff = min(diff, primes[i] - primes[i-1]);
                ans[0] = primes[i-1];
                ans[1] = primes[i]; 
            }
        }

        return ans;
    }
};