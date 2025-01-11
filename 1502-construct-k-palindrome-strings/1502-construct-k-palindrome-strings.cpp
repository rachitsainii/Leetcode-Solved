class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k){
            return false;
        }

        if(s.size() == k){
            return true;
        }

        unordered_map<char, int> counts;
        for(int i = 0; i < s.size(); i++){
            counts[s[i]]++;
        }

        int count_odd = 0;
        for(auto i : counts){
            if(i.second % 2 != 0){
                count_odd++;
            }
        }

        if(count_odd > k){
            return false;
        }

        return true;
        
    }
};