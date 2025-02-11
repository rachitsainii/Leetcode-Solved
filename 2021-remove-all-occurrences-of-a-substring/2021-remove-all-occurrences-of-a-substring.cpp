class Solution {
public:

    bool check(stack<char> &st, string part, int n){
        stack<char> tempSt = st;

        for(int idx = n-1; idx >= 0; idx--){
            if(tempSt.top() != part[idx]){
                return false;
            }

            tempSt.pop();
        }

        return true;
    }

    string removeOccurrences(string s, string part) {

        // Brute Force
        // while(true){
        //     int idx = s.find(part);

        //     if(idx == string::npos) {
        //         break;
        //     }

        //     s.erase(idx, part.length());
        // }

        // return s;

        // Using Stack
        stack<char> st;

        int m = s.size();
        int n = part.size();

        for(int i = 0; i < m; i++){
            st.push(s[i]);

            if(st.size() >= n && check(st, part, n) == true){
                for(int j = 0; j < n; j++){
                    st.pop();
                }
            }
        }

        string result = "";
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};