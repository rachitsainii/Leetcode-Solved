class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = words.size();
        int count = 0;
        unordered_set<char> check;
        for(auto i : allowed){
            check.insert(i);
        }

        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].length(); j++){
                if(!(check.find(words[i][j]) != check.end())){
                    ans--;
                    break;
                }  
            }
        }

        return ans;
    }
};