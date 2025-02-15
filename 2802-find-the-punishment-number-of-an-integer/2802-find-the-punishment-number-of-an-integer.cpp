class Solution {
public:

    bool check(string s, int num, int start, int currentSum){
        if(start == s.size()){
            return currentSum == num;
        }

        for(int i = 1; i <= s.size()-start; i++){
            string sub = s.substr(start, i);
            int val = stoi(sub);

            if(check(s, num, start+i, currentSum + val)){
                return true;
            }
        }

        return false;
    }


    int punishmentNumber(int n) {
        int ans = 0;

        for(int i = 1; i <= n; i++){
            int square = i * i;

            if(check(to_string(square), i, 0, 0)){
                ans += square;
            }
        }

        return ans;
    }
};