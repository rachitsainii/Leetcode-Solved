class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> onesRow(m, 0);
        vector<int> onesCol(n, 0);
        vector<int> zerosRow(m, 0);
        vector<int> zerosCol(n, 0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    onesRow[i]++;
                } else {
                    zerosRow[i]++;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[j][i] == 1){
                    onesCol[i]++;
                } else {
                    zerosCol[i]++;
                }
            }
        }

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }

        // for(auto i : onesRow){
        //     cout << i << " ";
        // }
        // cout << endl;

        // for(auto i : onesCol){
        //     cout << i << " ";
        // }
        // cout << endl;

        // for(auto i : zerosRow){
        //     cout << i << " ";
        // }
        // cout << endl;

        // for(auto i : zerosCol){
        //     cout << i << " ";
        // }
        // cout << endl;

        return ans;
        
    }
};