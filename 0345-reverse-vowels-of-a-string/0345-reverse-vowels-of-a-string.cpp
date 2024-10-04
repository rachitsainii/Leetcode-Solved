class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i','o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<char> x;
        for(int i = 0; i < s.size(); i++){
            if(vowels.find(s[i]) != vowels.end()){
                x.push_back(s[i]);
            }
        }

        int k = x.size() - 1;

        for(int i = 0; i < s.size(); i++){
            if(vowels.find(s[i]) != vowels.end()){
                s[i] = x[k];
                k--;
            }
        }

        return s;
    }
};