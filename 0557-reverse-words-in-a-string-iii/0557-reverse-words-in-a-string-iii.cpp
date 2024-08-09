class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = 0;
        int third = 0;
        s = s + ' ';
        string output = "";
        for (right = 0; right < s.length(); right++) {
            if(s[right] == ' '){
                third = right - 1;
            } else {
                continue;
            }

            while(left < third) {
                swap(s[left], s[third]);
                left++;
                third--;
            } 

            left = right + 1;
        }

        for(int i = 0; i < s.length()-1; i++){
            output += s[i];
        }

        return output ;
    }
};