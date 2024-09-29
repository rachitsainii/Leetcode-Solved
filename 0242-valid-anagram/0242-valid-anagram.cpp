class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count_s;
        unordered_map<char, int> count_second;
        for(auto i : s){
            count_s[i]++;
        }

        for(auto i : t){
            count_second[i]++;
        }

        if(count_s == count_second){
            return true; 
        } else {
            return false;
        }
    }
};