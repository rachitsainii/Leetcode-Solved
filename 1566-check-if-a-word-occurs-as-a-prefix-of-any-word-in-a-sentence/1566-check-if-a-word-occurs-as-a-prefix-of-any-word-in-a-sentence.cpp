class Solution {
public:

    vector<string> stringToVector(string s, int size){
        vector<string> result;
        string k = "";
        int x = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ' || x > size){
                result.push_back(k);
                k = "";
                x = 0;
            } else if(x < size) {
                k += s[i];
                x++;
            }
        }
        result.push_back(k);
        return result;
    }

    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> s;
        s = stringToVector(sentence, searchWord.size());
        for(int i = 0; i < s.size(); i++){
            if(s[i] == searchWord){
                return i+1;
            }
        }

        return -1;
    }
};