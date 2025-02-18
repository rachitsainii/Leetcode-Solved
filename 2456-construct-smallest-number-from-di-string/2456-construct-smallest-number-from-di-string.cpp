class Solution {
public:
    string smallestNumber(string pattern) {
        // Using stack
        // T. C - O(n)
        // S.C - O(n+1)

        int n = pattern.size();
        string num = "";
        int counter = 1;
        stack<char> st;
        for(int i = 0; i <= n; i++){
            st.push(counter + '0');
            counter++;
            if(i == n || pattern[i] == 'I'){
                while(!st.empty()){
                    num += st.top();
                    st.pop();
                }
            }
        }

        return num;
    }
};