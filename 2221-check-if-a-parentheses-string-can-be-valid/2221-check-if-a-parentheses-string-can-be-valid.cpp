class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        if(n % 2 != 0){
            return false;
        }


        stack<int> open;
        stack<int> openClose;

        for(int i = 0; i < s.size(); i++){
            if(locked[i] == '0'){
                openClose.push(i);
            } else if(s[i] == '('){
                open.push(i);
            } else if(s[i] == ')'){
                if(!open.empty()) {
                    open.pop();
                } else if(!openClose.empty()){
                    openClose.pop();
                } else {
                    return false;
                }
            }            

        }

        while(!open.empty() && !openClose.empty() && open.top() < openClose.top()){
            open.pop();
            openClose.pop();
        }

        return open.empty();
    }
};