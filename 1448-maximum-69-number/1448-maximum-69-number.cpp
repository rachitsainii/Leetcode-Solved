class Solution {
public:
    int maximum69Number (int num) {
        vector<int> digits;
        int ans = 0;
        while(num > 0){
            int digit = num % 10;
            digits.push_back(digit);
            num = num / 10;
        }

        reverse(digits.begin(), digits.end());

        for(int i = 0; i < digits.size(); i++){
            if(digits[i] == 6){
                digits[i] = 9;
                break;
            }
        }

       

        for(auto i : digits){
            ans = ans * 10 + i;
        }

        return ans;

    }
};