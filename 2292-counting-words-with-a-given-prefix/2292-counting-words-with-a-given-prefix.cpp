class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int len = pref.size();
        int ans = 0;
        for(auto word : words){
            int flag = 0;
            for(int i = 0; i < len; i++){
                if(word[i] != pref[i]){
                    flag = 1;
                    break;

                }
            }

            if(flag != 1){
                ans++;
            }
            
        }

        return ans;
    }
};