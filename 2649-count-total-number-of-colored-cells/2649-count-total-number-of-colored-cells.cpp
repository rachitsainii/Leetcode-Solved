class Solution {
public:
    long long coloredCells(int n) {
        if(n == 1){
            return n;
        }
        long long next = 1;
        for(int i = 1; i < n; i++){
            next = next + 4 *(i);
        }

        return next;
    }
};