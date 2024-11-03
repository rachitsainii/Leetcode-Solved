class Solution {
public:
    int addDigits(int num) {
        string s = to_string(num);

        while(s.size() >= 1){
            int k = 0;
            for(int i = 0; i < s.size(); i++){
                k += s[i] - '0';
            }
            string t = "";
            t = to_string(k);
            if(t.size() == 1){
                return (t[0] - '0');
            } else {
                s = t;
            }
        }

        return 0;
    }
};