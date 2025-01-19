class Solution {
public:
    typedef pair<int, pair<int, int>> PP;

    vector<vector<int>> directions = {{0,-1}, {0, 1}, {-1, 0}, {1, 0}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<PP, vector<PP>, greater<>> boundaryCells; // min-heap

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // left most col and right most col (0, n-1)
        for(int row = 0; row < m; row++){
            for(int col : {0, n-1}){
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }


        // top most col and bottom most row (0, m-1)
        for(int col = 0; col < n; col++){
            for(int row : {0, m-1}){
                boundaryCells.push({heightMap[row][col], {row, col}});
                 visited[row][col] = true;
            }
        }

        int water = 0;

        while(!boundaryCells.empty()){
            PP p = boundaryCells.top();
            boundaryCells.pop();


            int height = p.first;
            int i = p.second.first;
            int j = p.second.second;

            // find neighbours

            for(vector<int> &dir : directions){
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]){
                    water += max(height - heightMap[i_][j_], 0);

                    boundaryCells.push({max(height, heightMap[i_][j_]), {i_, j_}});

                    visited[i_][j_] = true;
                }
            }
        }

        return water;
    }
};