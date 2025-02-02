class Solution {
public:
    bool checkString(string s) {

        
        int n = s.size();
        int indexB = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == 'b'){
                indexB = i;
                break;
            }
        }

        if(indexB == -1){
            return true;
        }

        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                if(i > indexB){
                    return false;
                }
            }
        }

        return true;
    }
};