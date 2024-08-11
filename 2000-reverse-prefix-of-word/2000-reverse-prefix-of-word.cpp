class Solution {
public:
    string reversePrefix(string word, char ch) {
        string s = word;
        int left = 0;
        int right = 0;
        for (right = 0; right < s.length(); right++){
            if(s[right] == ch){
                break;
            }
        }

        if(right == s.length()){
            return s;
        } else {
             while(left < right){
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};