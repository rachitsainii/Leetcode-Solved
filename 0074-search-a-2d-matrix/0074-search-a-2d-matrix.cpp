class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int n = row*col;
        int start = 0;
        int end = n-1;
        int mid = start + (end - start)/2;

        while (start <= end){
            int rowIndex = mid / col;
            int colIndex = mid % col;
            int currentNumber = matrix[rowIndex][colIndex];

            if (currentNumber == target){
                return true;
            } else if (target > currentNumber){
                start = mid + 1;
            } else {
                end = mid - 1;
            }

            mid = start + (end - start) / 2;
        }

        return false;
    }
};