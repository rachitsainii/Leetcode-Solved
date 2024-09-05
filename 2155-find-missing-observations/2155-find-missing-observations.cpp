class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;
        int m = rolls.size();
        int sum = 0;
        int count = 0;
        for(int i = 0; i < m; i++){
            sum += rolls[i];
        }

        int total_size = m + n;
        if (((mean * total_size) - sum ) % n == 0){
            int val = ((mean * total_size) - sum ) / n;
            if(val > 6 || val < 1){
                return ans;
            } else {
                while(n != 0){
                    ans.push_back(val);
                    n--;
                }
                return ans;
            }
        } else {
            int extra = ((mean * total_size) - sum ) % n;
            int val = (((mean * total_size) - sum ) / n);
            if(val > 6 || val < 1){
                return ans;
            } else if(val + extra <=  6){
                ans.push_back(val + extra);
                while(n - 1 != 0){
                    ans.push_back(val);
                    n--;
                }
                return ans;
            } else {
                while(extra != 0){
                    if(val + 1 <= 6){
                        ans.push_back(val + 1);
                        extra--;
                        count++;
                    } else {
                        return ans;
                    }  
                }
                while(n - count !=0){
                    ans.push_back(val);
                    n--;
                }
                return ans;
            }
        }    
    }
};