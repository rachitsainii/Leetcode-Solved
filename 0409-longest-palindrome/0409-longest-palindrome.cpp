class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        unordered_map<char, int> c;
        for(auto i : s){
            c[i]++;
        }

        for(auto i : c){
            cout << i.first << " " << i.second << endl;
        }

        bool flag = false;
        for(auto [key, val] : c){
            if(val % 2 == 0){
                ans += val;
            } else if(val % 2 == 1 && flag == false){
                ans += val;
                flag = true;
            } else if(val % 2 == 1 &&  val != 1){
                ans += val - 1 ;
            }
        }

        return ans;
    }
};