class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    row[i]++;
                }
            }
        }

         for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[j][i] == 0){
                    col[i]++;
                }
            }
        }

        for(auto i : row){
            cout << i << " ";
        }
        cout << endl;

        for(auto i : col){
            cout << i << " ";
        }
        cout << endl;

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1 && row[i] == n-1 && col[j] == m-1){
                    ans++;
                }
            }
        }

        return ans;
    }
};