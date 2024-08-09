#include<string>

class Solution {
public:
    string reverseOnlyLetters(string s) {
        string x = "";
        string y = "";
        for (int i = 0; i < s.length(); i++) {
            if((int)s[i] >= 65 && (int)s[i] <= 90) {
                x += s[i];
            } else if((int)s[i] >= 97 && (int)s[i] <= 122) {
                x+= s[i];
            } else {
                y += s[i];
            }
        }

        int left = 0;
        int right = x.length()-1;
        while(left < right) {
            swap(x[left], x[right]);
            left++;
            right--;
        }

        int count = 0;
        for (int j = 0; j < s.length(); j++) {
            if((int)s[j] >= 65 && (int)s[j] <= 90) {
                continue;
            } else if((int)s[j] >= 97 && (int)s[j] <= 122) {
                continue;
            } else {
                x.insert(j, 1, y[count]);
                count++;
            }
        }

        return x;
    }
};