class Solution {
public:

    int m, n;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void bfs(int i, int j, vector<vector<char>> &grid){
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '$';

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(auto &dir : directions){
                int i_ = dir[0] + i;
                int j_ = dir[1] + j;

                if(i_ < 0 || j_ < 0 || i_ >= m || j_ >= n || grid[i_][j_] != '1'){
                    continue;
                } else {
                    q.push({i_, j_});
                    grid[i_][j_] = '$';
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int noOfIslands = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    bfs(i, j, grid);
                    noOfIslands++;
                }
            }
        }

        return noOfIslands;
    }
};