class Solution {
public:

    bool isPrefixAndSuffix(string str1, string str2){
        if(str1.size() > str2.size()){
            return false;
        }

        bool val1 = true;
        bool val2 = true;
        
        for(int i = 0; i < str1.size(); i++){
            if(str1[i] == str2[i]){
                continue;
            } else {
                val1 = false;
                break;
            }
        }

        int i = 0;
        for(int j = str2.size() - str1.size(); j < str2.size(); j++){
            if(str1[i] == str2[j]){
                i++;
                continue;
            } else {
                val2 = false;
                break;
            }
        }

        return val1 && val2;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int res = 0;
        for(int i = 0; i < words.size() ; i ++){
            for(int j = i + 1; j < words.size(); j++){
                bool ans = isPrefixAndSuffix(words[i], words[j]);
                if(ans == true){
                    res += 1;
                }
            }
        }

        return res;
    }
};