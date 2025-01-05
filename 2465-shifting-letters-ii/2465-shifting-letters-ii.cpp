class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        // Brute Force (TLE)

        // string ans = "";

        // for(int i = 0; i < shifts.size(); i++){
        //     int start = shifts[i][0];
        //     int end = shifts[i][1];
        //     int dir = shifts[i][2];

        //     if(dir == 0){
        //         for(int j = start; j <= end; j++){
        //             s[j] = char(((s[j] - 'a' - 1 + 26) % 26) + 'a');
        //         }
        //     } else {
        //         for(int j = start; j <= end; j++){
        //             s[j] = char(((s[j] - 'a' + 1 + 26) % 26) + 'a');
        //         }
        //     }
        // }

        // ans = s;
        // return ans;


        // Difference Array Approach
        
        int n = s.size();
        vector<int> diff(n,0);

        for(auto &shift : shifts){
            int start = shift[0];
            int end = shift[1];
            int dir = (shift[2] == 0) ? -1 : 1;

            diff[start] += dir;
            if(end+1 < n){
                diff[end+1] -= dir;
            } 
        }

       int sum = diff[0];
       for(int i = 1; i < diff.size(); i++){
        sum += diff[i];
        diff[i] = sum;
       }

       for(int i = 0 ; i < diff.size(); i++){
            int x = diff[i] % 26;

            if(x < 0){
                x += 26; // Wrap around
            }

            s[i] = char(((s[i] - 'a' + x) % 26) + 'a');
       }
       
        return s;
        
    }
};