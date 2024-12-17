class Solution {
public:
    int kthGrammar(int n, int k) {

        // Brute Force Solution : TLE

        // string s = "0";
        // string new_s = "";
        // for(int i = 2; i <= n; i++){
        //     for(int j = 0; j < s.size(); j++){
        //         if(s[j] == '0'){
        //             new_s += "01";
        //         } else {
        //             new_s += "10";
        //         }
        //     }

        //     // cout << "s: " << s << endl;
        //     // cout << "new_s: " << new_s << endl;

        //     s = new_s;
        //     new_s = "";
        // }


        // // cout << s << endl;
        // return s[k-1] - '0';  

        // Using Recursion

        if(n == 1 && k == 1){
            return 0;
        }

        int len = pow(2, n-1);
        int mid = len / 2;

        if(k <= mid){
            return kthGrammar(n-1, k);
        } else {
            return 1 - kthGrammar(n-1, k - mid);
        }

    }
};