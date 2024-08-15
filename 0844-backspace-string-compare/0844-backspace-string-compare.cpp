class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return buildString(s) == buildString(t);
    }

    string buildString(string s){
        string ans = "";
        for(auto ch : s){
            if(ch != '#'){
                ans.push_back(ch);
            } else if(!ans.empty()){
                ans.pop_back();
            }
        }

        return ans;
    }
};