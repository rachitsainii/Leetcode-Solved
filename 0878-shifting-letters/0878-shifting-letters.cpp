class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        string ans = "";
        
        long sum = 0;
        vector<long> prefix_sum(shifts.size());
        for(int i = 0; i < shifts.size(); i++){
            sum += shifts[i];
        }

        for(int i = 0 ; i < shifts.size(); i++){
            prefix_sum[i] = sum;
            sum -= shifts[i];
        }

        for(auto i : prefix_sum){
            cout << i << " ";
        }

        int j = 0;
        for(int i = 0; i < s.size(); i++){
            ans += char('a' + (((s[i] - 'a') + prefix_sum[j]) % 26));
            j++;
        }

        return ans;
    }
};