class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int p1 = 0;
        int p2 = 0;
        while(p1 < s.size() && p2 < spaces.size()){
            if(p1 == spaces[p2]){
                ans+= ' ';
                p2++;
            }
            ans += s[p1];
            p1++;
        }

        while(p1 < s.size()){
            ans += s[p1];
            p1++;
        }

        while(p2 < spaces.size()){
            ans += ' ';
            p2++;
        }

        return ans;
    }
};