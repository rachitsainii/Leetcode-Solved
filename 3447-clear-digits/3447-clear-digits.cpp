class Solution {
public:
    string clearDigits(string s) {
        unordered_set<char> digits = {'0', '1', '2', '3', '4', '5','6','7','8','9'};
        stack<char> st;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(digits.find(s[i]) == digits.end()){
                st.push(s[i]);
            } else {
                st.pop();
            }
        }

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};