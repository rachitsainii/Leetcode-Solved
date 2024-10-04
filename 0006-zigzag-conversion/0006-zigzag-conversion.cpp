class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1 || numRows > s.size()){
            return s;
        }

        vector<string> rows(numRows);

        int pos = 0;
        int currentRow = 0;
        bool goingDown = false;


        while(pos < s.size()){
            for(currentRow = 0; currentRow < numRows && pos < s.size(); currentRow++){
                rows[currentRow] += s[pos++];
            }

            currentRow--;

            for(int j = currentRow - 1; j > 0 && pos < s.size(); j--){
                rows[j] += s[pos++];
            }
        }

        for (int i = 0; i < numRows; i++) {
            cout << rows[i] << endl; 
        }

       
        string ans = "";
        for (const string& row : rows) {
            ans += row;
        }

        return ans; 
        
    }
};