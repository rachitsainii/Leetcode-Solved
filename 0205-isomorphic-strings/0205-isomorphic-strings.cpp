class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mappingStoT;
        unordered_map<char, char> mappingTtoS;
        for(int i = 0; i < s.size(); i++){

            if(mappingStoT.count(s[i]) && mappingStoT[s[i]] != t[i]){
                return false;
            }

             if(mappingTtoS.count(t[i]) && mappingTtoS[t[i]] != s[i]){
                return false;
            }

            mappingStoT[s[i]] = t[i];
            mappingTtoS[t[i]] = s[i];
        }

        for(auto i : mappingStoT){
            cout << i.first << ":" << i.second;
            cout << endl;
        }

        cout << endl;

        for(auto i : mappingTtoS){
            cout << i.first << ":" << i.second;
            cout << endl;
        }
        return true;
    }
};