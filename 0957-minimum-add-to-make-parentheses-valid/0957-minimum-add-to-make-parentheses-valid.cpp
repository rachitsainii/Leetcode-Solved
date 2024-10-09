class Solution {
public:
    int minAddToMakeValid(string s) {
        int openParenthesis = 0;
        int closeParenthesis = 0;
        for(auto i : s){
            if(i == '('){
                openParenthesis++;
            } else if(i == ')' && openParenthesis > 0){
                openParenthesis--;
            } else {
                closeParenthesis++;
            }
        }

        return openParenthesis + closeParenthesis;
    }
};