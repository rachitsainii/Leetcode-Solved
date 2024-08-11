class Solution {
public:
    int maxNumberOfBalloons(string text) {
       int ans = 0;
        unordered_map<char, int> counts;
        for(int i = 0; i < text.length(); i++){
            counts[text[i]]++;

        }
        
        for(auto i : counts){
            cout << i.first << " " << i.second << endl;
        }
        
        while((counts.find('b') != counts.end() && counts['b'] >= 1) && (counts.find('a') != counts.end() && counts['a'] >= 1) && (counts.find('l') != counts.end() && counts['l'] >= 2) && (counts.find('o') != counts.end() && counts['o'] >= 2) && (counts.find('n') != counts.end() && counts['n'] >= 1)){
             ans++;
             counts['b']--;
             counts['a']--;
             counts['l'] -=2;
             counts['o'] -=2;
             counts['n']--;
         }

         return ans;
    }   
};