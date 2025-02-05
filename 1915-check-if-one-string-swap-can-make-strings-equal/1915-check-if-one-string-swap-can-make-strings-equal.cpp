class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int p1 = 0;
        int p2 = 0;
        int n = s1.size();
        int m = s2.size();
        vector<char> s1Char;
        vector<char> s2Char;
        int nonEqualPos = 0;
        while(p1 < n && p2 < m){
            if(s1[p1] == s2[p2]){
                p1++;
                p2++;
            } else {
                nonEqualPos++;
                s1Char.push_back(s1[p1]);
                s2Char.push_back(s2[p2]);
                p1++;
                p2++;
            }
        }

        cout << nonEqualPos << endl;

      

        for(auto i : s1Char){
            cout << i << " ";
        }

        cout << endl;

        for(auto i : s2Char){
            cout << i << " ";
        }

        cout << endl;

        sort(s1Char.begin(), s1Char.end());
        sort(s2Char.begin(), s2Char.end());

        if(nonEqualPos == 0 ){
            return true; 
        } else if(nonEqualPos == 2 && ( s1Char  ==  s2Char)){
            return true;
        } else {
            return false;
        }

        return false;
    }
};