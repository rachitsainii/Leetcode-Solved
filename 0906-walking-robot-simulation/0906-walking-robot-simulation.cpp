class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int maxDist = 0;
        int x = 0, y = 0; // Robot's current coordinates
        int dir = 0;  //Index to track the current direction (0: north, 1: east, 2: south, 3: west)
        
        // Direction vectors for north, east, south, and west
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Set to store the obstacles. (Helps in quick lookup.)
        set<pair<int, int>> obs;
        for (const auto& ob : obstacles) {
            obs.insert({ob[0], ob[1]});
        }
        
        for (int cmd : commands) {
            if (cmd == -1) {
                // Turn right 90 degrees
                dir = (dir + 1) % 4;
            } else if (cmd == -2) {
                // Turn left 90 degrees
                dir = (dir + 3) % 4;  // Equivalent to (dir - 1 + 4) % 4
            } else {
                // Move forward in the current direction
                for (int i = 0; i < cmd; i++) {
                    int nextX = x + directions[dir].first;
                    int nextY = y + directions[dir].second;
                    if (obs.find({nextX, nextY}) != obs.end()) {
                        // There's an obstacle, stop moving
                        break;
                    }
                    // Update the robot's position
                    x = nextX;
                    y = nextY;
                    // Calculate the maximum distance from the origin
                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }
        
        return maxDist;
    }
};
