class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> valid = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char> st;
        for(auto i : s){
            if(valid.find(i) != valid.end()){
                st.push(i);
            } else {
                if(st.empty()){
                    return false;
                }

                char lastOpening = st.top();
                if(valid[lastOpening] != i){
                    return false;
                }
                st.pop();
            }
  
        }

        return st.empty(); 
    }
};