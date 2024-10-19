class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        while(n > 0){
            string rev = "";
            for(int i = 0; i < s.size(); i++){
                if(s[i] == '0'){
                    rev += '1';
                } else {
                    rev += '0';
                }
            }

            reverse(rev.begin(), rev.end());

            s = s + '1' + rev;
            n--;
        }

        return s[k-1];
    }
};