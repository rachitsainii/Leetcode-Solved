class Solution {
public:

    vector<string> stringToArray(string &s){
        vector<string> result;
        string word = "";
        for(auto i : s){
            i = tolower(static_cast<unsigned char>(i));
        }

        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                result.push_back(word);
                word = "";
            } else {
                word += s[i];
            }
        }

        result.push_back(word);

        return result;
    }

    bool isCircularSentence(string sentence) {
        vector<string> k = stringToArray(sentence);

        for(auto i : k){
            cout << i << " ";
        }

        if(k[0][0] != k[k.size()-1][k[k.size()-1].size()-1]){
            return false;
        }

        for(int i = 1; i < k.size(); i++){
            if(k[i][0] != k[i-1][k[i-1].size()-1]){
                return false;
            }
        }

        

        return true;
    }
};