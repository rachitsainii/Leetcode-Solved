class Solution {
public:

    vector<string> stringToVector(string &s){
        vector<string> ans;
        string k = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                ans.push_back(k);
                k = "";
            } else {
                k+= s[i];
            }
        }
        ans.push_back(k);
        return ans;
    }

    int canBeTypedWords(string text, string brokenLetters) {
        
        unordered_set<char> l;
        for(int i = 0; i < brokenLetters.size(); i++){
            l.insert(brokenLetters[i]);
        }

        vector<string> s = stringToVector(text);
        int ans = s.size();
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < s[i].size(); j++){
                if(l.find(s[i][j]) != l.end()){
                    ans--;
                    break;
                }
            }
        }

        for(auto i : l){
            cout << i << " ";
        }

        return ans;
    }
};