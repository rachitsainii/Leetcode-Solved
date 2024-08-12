class Solution {
public:

    string convertToKey(vector<int> &arr){
        string s = "";
        for(int i = 0; i < arr.size(); i++){
            s += to_string(arr[i]) + ",";
        }

        return s;
    }


    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> dic1;
        for(vector<int> row: grid){
            dic1[convertToKey(row)]++;
        }

        unordered_map<string, int> dic2;
        for(int col = 0; col < grid[0].size(); col++){
            vector<int> currCol;
            for(int row = 0; row < grid.size(); row++){
                currCol.push_back(grid[row][col]);
            }

            dic2[convertToKey(currCol)]++;
        }

        int ans = 0;
        for(auto [arr, val] : dic1){
            ans += val * dic2[arr];
        }

        return ans;

        for(auto [key, val] : dic1){
        cout << key << " " << val << endl;
        }

        cout << endl;

        for(auto [key, val] : dic2){
        cout << key << " " << val << endl;
        }

    }
};