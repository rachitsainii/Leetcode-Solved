class Solution {
public:
    int maxScore(string s) {
        vector<int> ones;
        vector<int> zeros;
        int n = s.size();
        int count_0 = 0;
        for(int i = 0; i < n-1; i++){
            int count_1 = 0;
            if(s[i] == '0'){
                count_0++;
            }
            for(int j = i + 1; j < n; j++){
                if(s[j] == '1'){
                    count_1++;
                }
            }

            ones.push_back(count_1);
            zeros.push_back(count_0);
        }

        // for(auto i : ones){
        //     cout << i << " " ;
        // }

        // cout << endl;

        //  for(auto i : zeros){
        //     cout << i << " " ;
        // }

        int ans = 0;
        int sum = 0;
        for(int i = 0 ; i < ones.size(); i++){
            sum = ones[i] + zeros[i];
            ans = max(ans, sum);
        }

        return ans;
    }
};