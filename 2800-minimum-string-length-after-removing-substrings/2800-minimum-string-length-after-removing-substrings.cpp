class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        while(s.size() > 0){
            for(int i = 1; i < s.size(); i++){
            if((s[i-1] == 'A' && s[i] == 'B') || (s[i-1] == 'C' && s[i] == 'D')){
                s[i-1]= '#';
                s[i] = '#';
                }
            }


            string new_s = "";

            for(int i = 0; i < s.size(); i++){
                if(s[i] != '#'){
                    new_s += s[i];
                }
            }

            if(new_s.size() == s.size()){
                return s.size();
            } else {
                s.size() - new_s.size();
                s = new_s;
            }
        }
        

        

        for(auto i : s){
            cout << i;
        }

        return s.size();
    }
};