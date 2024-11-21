class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, '0'));

        // Mark guards and walls
        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = 'G'; // Guard
        }
        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = 'W'; // Wall
        }

        // Direction vectors for up, down, left, right
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Mark guarded cells
        for (auto& guard : guards) {
            int x = guard[0], y = guard[1];
            for (auto& dir : directions) {
                int dx = dir[0], dy = dir[1];
                int nx = x + dx, ny = y + dy;

                while (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    if (grid[nx][ny] == 'W' || grid[nx][ny] == 'G') break; // Stop at wall or guard
                    if (grid[nx][ny] == '0') grid[nx][ny] = '1'; // Mark as guarded
                    nx += dx;
                    ny += dy;
                }
            }
        }

        // Count unguarded cells
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') {
                    count++;
                }
            }
        }

        return count;
    }
};
