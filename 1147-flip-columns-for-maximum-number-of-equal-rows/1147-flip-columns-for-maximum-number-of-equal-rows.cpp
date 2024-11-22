class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();


        int maxRows = 0;

        for(auto row : matrix){
            vector<int> inverted(n);

            for(int col = 0; col < n; col++){
                inverted[col] = row[col] == 0 ? 1 : 0; // Flip
            }

            int count = 0;
            for(auto r : matrix){
                if(r == row || r == inverted){
                    count++;
                }
            }

            maxRows = max(maxRows, count);
        }

        return maxRows;
    }
};