class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> positions;

        int m = mat.size();
        int n = mat[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                positions[mat[i][j]] = {i, j};
            }
        }

        for(auto i : positions){
            cout << i.first << "- " << "{"<< i.second.first << ", " << i.second.second << "}" << endl;
        }

        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        for(int i = 0; i < arr.size(); i++){
            auto [r, c] = positions[arr[i]];

            rowCount[r]++;
            colCount[c]++;

            if(rowCount[r] == n){
                return i;
            }

            if(colCount[c] == m){
                return i;
            }
        }

        return -1;
    }
};