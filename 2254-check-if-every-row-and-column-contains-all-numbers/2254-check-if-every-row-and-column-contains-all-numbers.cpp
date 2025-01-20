class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        unordered_set<int> s;
        for(int i = 1 ; i <= n; i++){
            s.insert(i);
        }

       

        for(int i = 0; i < n; i++){
            unordered_set<int> copy = s;
            for(int j = 0 ; j < n; j++){
                if(copy.find(matrix[i][j]) == copy.end()){
                    return false;
                } else {
                    copy.erase(matrix[i][j]);
                }
            }
        }


        for(int i = 0; i < n; i++){
            unordered_set<int> copy2 = s;
            for(int j = 0; j < n; j++){
                if(copy2.find(matrix[j][i]) == copy2.end()){
                    return false;
                } else {
                    copy2.erase(matrix[j][i]);
                }
            }
        }

        return true;
    }
};