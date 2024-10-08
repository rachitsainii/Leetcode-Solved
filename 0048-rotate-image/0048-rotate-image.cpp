class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i+1; j < matrix[i].size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        
        for(int i = 0; i < matrix.size(); i++){
            int left = 0;
            int right = matrix[0].size() - 1;
            while(left <= right){
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }
    }
};