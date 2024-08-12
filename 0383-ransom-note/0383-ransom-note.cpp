class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       //  string comparison = "";
        unordered_map<char, int> magazine_counts;
        for(int i = 0; i < magazine.size(); i++){
            magazine_counts[magazine[i]]++;
        }

        for(auto [key, val] : magazine_counts){
            cout << key << " " << val << endl;
        }

        for(int j = 0; j < ransomNote.size(); j++){
            if(magazine_counts.find(ransomNote[j]) != magazine_counts.end() && magazine_counts[ransomNote[j]] > 0){
                // comparison += ransomNote[i];
                magazine_counts[ransomNote[j]]--;
            } else {
                return false;
            }
        }

        return true;
    }
};