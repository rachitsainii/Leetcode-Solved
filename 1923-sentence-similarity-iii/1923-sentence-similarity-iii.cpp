class Solution {
public:

    vector<string> sentenceToArray(string s){
        vector<string> ans;
        string word = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                ans.push_back(word);
                word = "";
            } else {
                word += s[i];
            }
        }
        ans.push_back(word);
        return ans;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1 = sentenceToArray(sentence1);
        vector<string> s2 = sentenceToArray(sentence2);
        // unordered_set<string> first(s1.begin(), s1.end());
        // unordered_set<string> copy(first);
        // unordered_set<string> second(s2.begin(), s2.end());
        

        // for(auto i : second){
        //     if(first.find(i) != first.end()){
        //         copy.erase(i);
        //     }
        // }

        if (s1.size() > s2.size()) {
            swap(s1, s2);
        }

        int i = 0;
        while( i < s1.size() && s1[i] == s2[i]){
            i++;
        }

        int j = s1.size() - 1;
        int k = s2.size() - 1;

        while(j >= 0 && s1[j] == s2[k]){
            j--;
            k--;
        }
        
        return i > j;
    }
};