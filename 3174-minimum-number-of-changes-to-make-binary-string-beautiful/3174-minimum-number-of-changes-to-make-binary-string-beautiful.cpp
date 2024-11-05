class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        for(int i = 1; i < s.size(); i+=2){
            if(s[i] == s[i-1]){
                continue;
            } else if(s[i] == '1' && s[i-1] == '0'){
                s[i] = '0';
                ans++;
            } else {
                s[i] = '1';
                ans++;
            }
        }

        cout << s << endl;

        return ans;
    }
};