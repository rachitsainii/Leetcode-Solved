class Solution {
public:

    bool isSubset(vector<int> &freq2, vector<int> &temp){
        for(int i = 0; i < 26; i++){
            if(temp[i] < freq2[i]){
                return false;
            }
        }

        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        vector<int> freq2(26);

        for(auto i : words2){
            int temp[26] = {0};
            for(auto j : i){
                temp[j - 'a']++;

                freq2[j-'a'] = max(freq2[j-'a'], temp[j - 'a']);
            }      
        }

        for(auto i: words1){
            vector<int> temp(26, 0);
            for(auto j : i){
                temp[j - 'a']++;
            }

            if(isSubset(freq2, temp) == true){
                result.push_back(i);
            }
        }


        return result;
    }
};