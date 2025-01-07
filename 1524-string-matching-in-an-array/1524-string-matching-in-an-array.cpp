class Solution {
public:

    bool matchString(string s1, string s2){
        if(s1.size() > s2.size()){
            return false;
        } else {
            int p1 = 0;
            int p2 = 0;
            while(p1 < s1.size() && p2 < s2.size()){
                if(s1[p1] == s2[p2]){
                    p1++;
                    p2++;
                } else {
                    p2 = p2 - p1 + 1;;
                    p1 = 0;
                }
            }

            if(p1 == s1.size()){
                return true;
            } else {
                return false;
            }
        }
    }

    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> s;
        for(int i = 0 ; i < words.size(); i++){
            for(int j = 0; j < words.size(); j++){
                if(i == j){
                    continue;
                }

                bool res = matchString(words[i], words[j]);

                if(res == true){
                    s.insert(words[i]);
                }
            }
        }

        for(auto i : s){
            ans.push_back(i);
        }

        return ans;
    }
};