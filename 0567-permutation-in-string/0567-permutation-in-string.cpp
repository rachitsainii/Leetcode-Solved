class Solution {
public:

    bool areMapsEqual(const unordered_map<char, int> &map1, const unordered_map<char, int> &map2){
        for(auto entry: map1){
            if(map2.find(entry.first) == map2.end() || map2.at(entry.first) != entry.second){
                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if( n > m){
            return false;
        }
        unordered_map<char, int> counts;
        unordered_map<char, int> windowCount;

        for(auto i : s1){
            counts[i]++;
        }

        for(int i = 0; i < n; i++){
            windowCount[s2[i]]++;
        }

        for(int i = s1.size(); i < s2.size(); i++){
            if(areMapsEqual(counts, windowCount)){
                return true;
            }

            windowCount[s2[i]]++;
            windowCount[s2[i-s1.size()]]--;

            if(windowCount[s2[i-n]] == 0){
                windowCount.erase(s2[i-n]);
            }
        }

        return areMapsEqual(counts, windowCount);
    }
};