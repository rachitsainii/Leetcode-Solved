class Solution {
public:

    int Z, O;
    int L, H;

    const int M = 1e9 + 7;

    int solve(int l, vector<int> &t){
        if(l > H){
            return 0;
        }

        if(t[l] != -1){
            return t[l];
        }

        bool addOne = false;
        if(l >= L && l <= H){
            // 1 add karna padega
            addOne = true;
        }

        int append_zero = solve(l+Z, t);
        int append_one = solve(l+O, t);

        return t[l] = (addOne + append_zero + append_one)%M;

    }

    int countGoodStrings(int low, int high, int zero, int one) {
        
        L = low;
        H = high;

        Z = zero;
        O = one;

        vector<int> t(high+1, -1);

        return solve(0, t); // Solve("");
    }
};