class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
    // Brute Force : TLE
    //     int ans = 0;
    //     while(true) {
    //         for(int i = 0; i < chalk.size(); i++){
    //             if(chalk[i] > k ){
    //                 ans = i;
    //                 return ans;
    //             } else {
    //                 k -= chalk[i];
    //             }
    //         }
    //     }

    // Optimized
    int ans = -1;
    long long  sum = 0;
    for(int i = 0; i < chalk.size(); i++){
        sum += chalk[i];
    }

    k = k % sum;

    for(int i = 0; i < chalk.size(); i++){
        if(chalk[i] > k){
            ans = i;
            return ans;
        } else {
            k -= chalk[i];
        }
    }

    cout << sum << endl;

    return -1;

    }
};