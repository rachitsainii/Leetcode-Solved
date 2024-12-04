class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int p1 = 0;
        int p2 = 0;
        int count = 0;
        while(p1 < str1.size() && p2 < str2.size()){
            if(str1[p1] == str2[p2]){
                p1++;
                p2++;
                count++;
            } else {
                char c = str1[p1];
                c = 'a' + (c - 'a' + 1) % 26;
                str1[p1] = c;
                if(str1[p1] == str2[p2]){
                    p1++;
                    p2++;
                    count++;
                } else {
                    p1++;
                }
            }

            if(count == str2.size()){
                return true;
            } 
        }

        return false;
    }
};