class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int string1 = 0;
        int string2 = 0;
        while(string1 != word1.size() && string2  != word2.size()){
            ans += word1[string1];
            ans += word2[string2];
            string1++;
            string2++;
        }

        while(string1 != word1.size()){
            ans += word1[string1];
            string1++;
        }

        while(string2 != word2.size()){
            ans += word2[string2];
            string2++;
        }

        return ans;
    }
};