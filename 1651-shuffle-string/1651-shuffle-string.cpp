class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        string ans = "";
        vector<char> shuffled(n);
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            shuffled[indices[i]] = c;
        }

        for(auto i : shuffled){
            ans+= i;
        }

        return ans;
    }
};