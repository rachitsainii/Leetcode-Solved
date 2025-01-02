class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        // Brute Force

        // vector<int> ans;

        // int n = words.size();
        // // O(1) Space
        // unordered_set<char> v = {'a', 'e', 'i', 'o', 'u'};

        // vector<int> vowel(n, 0);

        // // O(n) Time
        // for(int i = 0; i < words.size(); i++){
        //     if((v.find(words[i][0]) != v.end()) && (v.find(words[i][words[i].size()-1]) != v.end())){
        //         vowel[i]++;
        //     }
        // }

        // for(auto i : vowel){
        //     cout << i << " ";
        // }

        // cout << endl;

        // for(int i = 0; i < queries.size(); i++){
        //     int total = 0;
        //     int left = queries[i][0];
        //     int right = queries[i][1];

        //     for(int j = left; j <= right; j++){
        //         total += vowel[j];
        //     }

        //     ans.push_back(total);

        // }

        // return ans;


        // Optimized

        vector<int> ans;

        int n = words.size();
        // O(1) Space
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u'};

        vector<int> vowel(n, 0);

        // O(n) Time
        int prefix_sum = 0;
        for(int i = 0; i < words.size(); i++){
            if((v.find(words[i][0]) != v.end()) && (v.find(words[i][words[i].size()-1]) != v.end())){
               prefix_sum++;
               vowel[i] = prefix_sum;
            } else {
                vowel[i] = prefix_sum;
            }

        }

        for(auto i : vowel){
            cout << i << " ";
        }

        cout << endl;


        for(int i = 0; i < queries.size(); i++){
            int left = queries[i][0];
            int right = queries[i][1];

            int total = vowel[right] - ((left > 0) ? vowel[left-1] : 0);

            ans.push_back(total);

        }

        // return ans;


        return ans;


    }
};