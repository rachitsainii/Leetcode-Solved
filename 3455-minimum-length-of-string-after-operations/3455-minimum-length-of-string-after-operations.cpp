class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> counts;
        for(int i = 0; i < s.size(); i++){
            counts[s[i]]++;
        }

        int ans = 0;
        for(auto i : counts){
            if(i.second % 2 == 0){
                ans+=2;
            } else {
                ans += 1;
            }
        }

        return ans;
    }
};