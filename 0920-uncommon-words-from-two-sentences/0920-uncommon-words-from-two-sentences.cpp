class Solution {
public:

    vector<string> string_split(string &s, char c){
        vector<string> result;
        string word = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == c || i == s.size()){
                result.push_back(word);
                word = "";
            } else {
                word += s[i];
            }
        }

        result.push_back(word);

        return result;
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        vector<string> split_s1;
        vector<string> split_s2;
        split_s1 = string_split(s1, ' ');
        split_s2 = string_split(s2, ' ');
        unordered_map<string, int> counts;

        for(auto i : split_s1){
            counts[i]++;
        }

        for(auto i : split_s2){
            counts[i]++;
        }

        for(auto i : counts){
            if(i.second == 1){
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};