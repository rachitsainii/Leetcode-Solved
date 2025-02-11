class Solution {
public:
    string removeOccurrences(string s, string part) {

        // Brute Force
        while(true){
            int idx = s.find(part);

            if(idx == string::npos) {
                break;
            }

            s.erase(idx, part.length());
        }

        return s;
    }
};