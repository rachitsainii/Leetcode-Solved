class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> mp;
        unordered_set<char> st = {'a', 'b', 'c'};
        int ans = 0;
        while(right < s.size()){
            if(st.find(s[right]) != st.end()){
                mp[s[right]]++;
            }

            while(mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1){
                ans += s.size() - right;
                mp[s[left]]--;
                left++;
            }

            right++;
        }

        return ans;
    }
};