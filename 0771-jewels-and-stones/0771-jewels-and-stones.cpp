class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelSet;
        int ans = 0;
        for(int i = 0; i < jewels.length(); i++){
            jewelSet.insert(jewels[i]);
        }

        for(int j = 0; j < stones.length(); j++){
            if(jewelSet.find(stones[j]) != jewelSet.end()){
                ans++;
            } 
        }
        

        return ans;
    }
};