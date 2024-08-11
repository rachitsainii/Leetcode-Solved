class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> counts;
        for(int i = 0; i < s.length(); i++){
            counts[s[i]]++;
        }
        
        unordered_set<int> frequencies;
        for(auto i : counts) {
           frequencies.insert(i.second);
        }

        return frequencies.size() == 1;
    }
};