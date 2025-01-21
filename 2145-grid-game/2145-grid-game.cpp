class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowRemSum = accumulate(begin(grid[0]), end(grid[0]), 0LL);

        long long secondRowRemSum = 0;

        long long minimizedRobot2Sum = LONG_LONG_MAX;

        for(int robot1Col = 0; robot1Col < grid[0].size(); robot1Col++){
            // Robot1 took this strategy
            firstRowRemSum -= grid[0][robot1Col];

            // Robot2 will try to take the best from the remaining.
            long long bestOfRobot2 = max(firstRowRemSum, secondRowRemSum);

            minimizedRobot2Sum = min(minimizedRobot2Sum, bestOfRobot2);

            secondRowRemSum += grid[1][robot1Col];

        }

        return minimizedRobot2Sum;
    }
};