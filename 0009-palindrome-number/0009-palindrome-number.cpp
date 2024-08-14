class Solution {
public:
    bool isPalindrome(int x) {
        int y = x;
        if (x < 0){
            return false;
        }
        unsigned long long int rev_num = 0;
        while (x > 0){
            int digit = x % 10;
            x = x / 10;
            rev_num = rev_num*10 + digit;
        }
        cout << rev_num << " " << x << endl;
        if(rev_num == y){
            return true;
        } else {
            return false;
        }
    }
};