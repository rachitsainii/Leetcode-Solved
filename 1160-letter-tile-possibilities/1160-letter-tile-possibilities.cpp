class Solution {
public:

    int n;
    void solve(string &tiles, vector<bool> &used, unordered_set<string> &result, string &curr){
        result.insert(curr);

        for(int i = 0; i < n; i++){
            if(used[i]){
                continue;
            }

            // Do
            used[i] = true;
            curr.push_back(tiles[i]);

            // Explore
            solve(tiles, used, result, curr);

            // Undo
            used[i] = false;
            curr.pop_back();
        }
    }
    

    int numTilePossibilities(string tiles) {
        n = tiles.size();

        vector<bool> used(n, false);
        unordered_set<string> result;

        string curr = "";

        solve(tiles, used, result, curr);

        return result.size() - 1; // Exclude empty subsequence
    }
};