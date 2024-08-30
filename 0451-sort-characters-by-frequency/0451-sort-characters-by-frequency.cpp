class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        vector<pair<char, int>> count_pair;
        string ans = "";
        for(auto i : s){
            count[i]++;
        }

        for(auto i : count){
            pair<char, int> x = make_pair(i.first, i.second);
            count_pair.push_back(x);
        }

       sort(count_pair.begin(), count_pair.end(), [](auto& a, auto& b) { 
        return a.second > b.second; 
    });

        for(auto i : count_pair){
            while(i.second > 0){
                ans += i.first;
                i.second--;
            }
        }

        for(auto i : count_pair){
            cout << i.first << ":" << i.second << endl;
        }

        return ans;
    }
};