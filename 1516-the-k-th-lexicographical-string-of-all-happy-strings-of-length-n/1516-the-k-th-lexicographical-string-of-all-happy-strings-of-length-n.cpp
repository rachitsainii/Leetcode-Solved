class Solution {
public:

    void solve(string &curr, vector<string> &result, int n){
        if(curr.size() == n){
            result.push_back(curr);
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++){
            if(!curr.empty() && curr.back() == ch){
                continue;
            }

            // DO
            curr.push_back(ch);

            // EXPLORE
            solve(curr, result, n);

            // UNDO
            curr.pop_back();
        }

    }

    string getHappyString(int n, int k) {
        // Generating all possible sequences of n -> Backtracking

        // 1. Generate all the strings
        // 2. Sort in lexographical order
        // 3. return result[k-1];

        // DO -> EXPLORE -> UNDO
        string curr = "";
        vector<string> result;
        solve(curr, result, n);

        if(result.size() < k){
            return "";
        }

        return result[k-1];
    }
};