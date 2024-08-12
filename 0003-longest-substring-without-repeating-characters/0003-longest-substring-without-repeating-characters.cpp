class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> counts;
        int ans = 0;
        int start = 0;
        for(int i = 0; i < s.length(); i++){
            if((counts.find(s[i]) != counts.end()) && counts[s[i]] >= start){
                start = counts[s[i]] + 1;
            }

            counts[s[i]] = i;
             ans = max(ans, i - start + 1);
            
        }

        for(auto [key, val] : counts){
            cout << key << " " << val << endl;
            cout << ans << endl;;
        }

       

        return ans;
    }
};