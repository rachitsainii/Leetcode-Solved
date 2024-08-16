class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string portion;
        while(getline(ss, portion, '/')){
            if(portion == ".."){
                if(!stack.empty()){
                    stack.pop_back();
                }
            } else if (portion == "." || portion == ""){
                continue;
            } else {
                stack.push_back(portion);
            }
        }

        string final_str = "/";
        for(int i = 0; i < stack.size(); i++){
            final_str += stack[i];
            if(i < stack.size()-1){
                final_str += "/";
            }
        }

        return final_str;
    }
};