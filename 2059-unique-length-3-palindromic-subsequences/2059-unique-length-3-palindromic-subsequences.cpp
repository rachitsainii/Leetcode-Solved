class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> c;
        int ans = 0;
        for(int i = 0 ; i < s.size(); i++){
            c.insert(s[i]);
        }

        for(auto i : c){
            unordered_set<int> palindrome;
            int left = 0;
            int right = s.size() - 1;
            for(int j = 0 ; j < s.size(); j++){
                if(s[j] == i){
                    left = j;
                    break;
                }
            }

            for(int k = s.size()-1; k >= 0; k--){
                if(s[k] == i){
                    right = k;
                    break;
                }
            }

            if(left != right){
                for(int x = left+1; x < right; x++){
                    palindrome.insert(s[x]);
                }
            } 
            ans+= palindrome.size();
            cout << ans << endl;
            palindrome.clear();
        }

        return ans;
    }
};