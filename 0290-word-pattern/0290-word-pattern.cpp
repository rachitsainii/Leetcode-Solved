class Solution {
public:

    vector<string> stringToVector(string k){
        vector<string> result;
        string str = "";
        for(int i = 0; i < k.size(); i++){
            if(k[i] == ' '){
                result.push_back(str);
                str = "";
            } else {
                str += k[i];
            }
        }
        result.push_back(str);
        return result;
    }

    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        vector<string> k = stringToVector(s);

        if(pattern.size() != k.size()){
            return false;
        }

        for(int i = 0; i < pattern.size(); i++){
            
            char c = pattern[i];
            string word = k[i];

            if(map1.find(c) != map1.end() && map1[c] != word){
                return false;
            }

            if(map2.find(word) != map2.end() && map2[word] != c){
                return false;
            }

            map1[c] = word;
            map2[word] = c;
 
        }

        

        for(auto i : map1){
            cout << i.first << " " << i.second << endl;
        }

        cout << endl;

         for(auto i : map2){
            cout << i.first << " " << i.second << endl;
        }

        return true;
    }
};